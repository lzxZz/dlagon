#ifndef DLAGON_EXCPTION_H_
#define DLAGON_EXCPTION_H_

#include <string>
namespace dlagon{

class Failed_bind_excption
{
  public:
    Failed_bind_excption(std::string m = "") : msg(m)
    {
    }
    ~Failed_bind_excption() = default;                       //默认析构
    Failed_bind_excption(Failed_bind_excption &) = default;  //默认拷贝构造
    Failed_bind_excption(Failed_bind_excption &&) = default; //默认移动构造
    std::string const &message() const
    {
        return this->msg;
    }

  private:
    std::string msg; //异常消息
};

class Failed_read_excption
{
  public:
    Failed_read_excption(std::string m = "") : msg(m)
    {
    }
    ~Failed_read_excption() = default;                       //默认析构
    Failed_read_excption(Failed_read_excption &) = default;  //默认拷贝构造
    Failed_read_excption(Failed_read_excption &&) = default; //默认移动构造
    std::string const &message() const
    {
        return this->msg;
    }

  private:
    std::string msg; //异常消息
};

class Failed_listen_excption
{
  public:
    Failed_listen_excption(std::string m = "") : msg(m)
    {
    }
    ~Failed_listen_excption() = default;                         //默认析构
    Failed_listen_excption(Failed_listen_excption &) = default;  //默认拷贝构造
    Failed_listen_excption(Failed_listen_excption &&) = default; //默认移动构造
    std::string const &message() const
    {
        return this->msg;
    }

  private:
    std::string msg; //异常消息
};
}

#endif // DLAGON_EXCPTION_H_