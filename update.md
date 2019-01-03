> 说明: 本文件为项目更新日志

# 2019.1.3 更新
1. Path类中新增拷贝赋值运算符,用于vector中的拷贝操作

1. 新增Server类,用于完成框架的主体任务
1. 新增Handler类,用于处理具体的HTTP请求
1. 新增Route类,用于将HTTP请求传递给对应的Handler进行处理
1. 新增Server示例,**但是目前无法运行**
## bug
1. Path类雀巢拷贝赋值运算符

# 2019.1.2 更新
1. 追加更新日志
构思Server的构成

# 2019.1.1 更新
1. HttpResponseHeader添加arg_table_成员,用于存放参数表.
1. HttpResponse声明中添加常量和非常量版本的Header()方法,新增SetBody(),用于重新设置函数体.
1. 将HttpResponse中的成员修改为非常量对象.
1. 临时实现了200的HTTP响应协议头
1. 实现了HttpResponse的ToString方法.将其转换为能够直接通过Socket发送的字符串.
1. 实现了response_protocol的ToString方法.
1. 新增使用HttpServer和HttpClient构成的基本HTTP服务器示例

# 2018.12.31 更新
1. 添加HttpClient和HttpServer
1. 更新dlagon.h
1. 添加HttpResponse声明
1. TCPClientSocket添加若干构造函数, 添加返回智能指针的方法,用于构造.
1. 将http/request文件更名为http/http_request.

# 2018.12.30 更新
1. 将Socket重构为基类,只持有套接字描述符,不再持有具体行为
1. 新增TcpSocket和UdpSocket,从Socket派生,添加具体行为
1. 新增TCPServerSocket和TcpClientSocket,隐藏不需要的行为.
1. 修复示例,满足新版本的运行
1. 在dlagon:net命名空间下新增tcp和udp两个命名空间.用于放置tcp和udp相关的类.
1. 暂时停止对UDP的支持.先集中精力完成HTTP框架的编写.

1. 目前新增的代码没有注释

# 2018.12.27 更新
1. 修改Socket,使用shared_ptr持有文件描述符
1. 新增ClientSocket和ServerSocket类,对Socket进行封装,隐藏了部分接口.
1. ClientSocket分离式编译失败,所有实现移动到头文件中
1. 新增ClientSocket实现的daytime客户端程序
1. 新增ServerSocket实现的daytime服务端程序

## bug
1. 在将Socket转为ClientSocket时,出现问题,多次调用析构函数


# 2018.12.26 更新
1. 更改Socket::Accept()函数签名,使用智能指针+元组同时返回套接字和地址信息.
1. 将Socket::Receive函数中readn修改为read系统调用.
1. 将Socket类中函数全部声明为后置返回类型风格.

# 2018.12.25 更新
添加异常类,取消所有的返回右值引用的函数,在EndPoint中发生了字节丢失的问题.

# 2018.12.24 更新
给所有文件添加版权声明,添加注释

# 2018.12.22 更新
新建项目使用cmake进行编译.
添加tools文件夹,放置编译脚本.编译脚本自动创建构建文件夹并编译.

# 2018.12.21 更新
项目重构崩盘

重新设计整体架构,重新构建,添加example,test等文件夹.并完善.

# 2018.12.7 更新
更新Makefile文件,添加std=c++11选项,移除不必要的libunp.a

Server中新增对请求的过滤.使用`allow_path`添加允许访问的正则表达式.

# 2018.12.3 问题列表
1. 无法获取post请求的请求体.只能拿到请求头.
2. get请求参数没有正常剥离.
3. 为响应设置文件作为返回内容的时候,需要手动设置MIME类型,需要支持自动设置.

> 下一步内容
1. 正确读取post请求体
2. 新增类,Arguments.键值对的形式存储请求头中的参数.


# 2018.12.3更新
修复若干bug,修复`Server_socket`类头文件中依赖不完整的问题.
新增加了`dlagon.h`头文件.包含了所有的头文件.
新增了基础的例子.

Makefile中新增了Release伪目标,生成libdlagon.a静态库,并和头文件一起拷贝到release文件夹下.



# 2018.12.1更新
将server中处理每一个链接的任务移动到新添加的Handler类.在Server中实现Handler池.每一个Handler占用一个线程.
在Server中添加`Client_Queue`,Handler从这个队列中逐个逐个处理.

更新readme文件

> #预计重构内容
> 1. 添加路由类,让Server持有一个路由,通过路由调用处理函数.
> 1. 让处理函数支持更多的参数,使用更加灵活.
> 1. 优化Response类,让直接返回文件能够自动识别MIME类型


# 2018.11.27更新
调整项目结构.
确定框架运行目前如下:
启动框架调用`Serve.run(port=8080)`,`Sever`类基于`Server_Socket`
`Server`接收到请求会返回一个`Client`对象.`Client`类基于`Client_Socket`
`Client`,解析`Http请求`,生成`HttpRequest`.
`Client`遍历`Server.register(Path,Recall)`列表,寻找匹配的`Recall`函数
`Client`调用`ReCall(HttpRequest) -> HttpResponse`,进行处理.
`Client`调用`Client << HttpResponse`将结果返回.

需要的类:
* `Socket`
* `ServerSocket`
* `ClientSocket`
* `HttpRequest`
* `HttpResponse`
* `Client`
* `Server`
* `Path`
* 以及其他的辅助类.

`ReCall`函数原型:
```cpp
HttpResponse handler(HttpRequest req);
```

