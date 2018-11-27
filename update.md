> 说明: 本文件为项目更新日志

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

