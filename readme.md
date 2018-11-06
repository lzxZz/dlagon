# 项目结构说明:
**目前项目还属于初始阶段,因此多个不同的模块共用一个文件,尤其在defs.h文件中**

## 类定义:
1. Server类  
    用于启动一个服务,逻辑代码全部编写在`Server::run()`中
2. Server_socket类
    用于监听端口号的套接字类,其中`bind`,`listen`方法都会返回套接字本身,用于支持链式调用
3. Socket类
    套接字类,支持使用`>>`和`<<`进行读(未实现)写.
    写套接字时,支持字符串,数字,Http_Response对象.
4. Http_Request类
    http请求头的封装,
5. Http_Response类
    http响应的封装
6. 异常类
    目前定义了`bind`和`listen`两个异常,在`server_socket`的对应函数中会抛出
7. 枚举类
    目前定义了`Http_method`枚举类,`Mime_type`暂未实现.




### 18.11.4 
`server.cpp`中新增全局常量,`root_dir`,用于指定返回文件的根目录.

基于UNP一书的C++封装,意图建立一个简单http服务器框架.