> 说明: 本文件为项目更新日志
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
