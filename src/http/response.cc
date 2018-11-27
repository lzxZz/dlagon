#include "http/response.h"

#include "excption.h"

using std::string;
using std::ifstream;

void dlagon::Http_Response::set_body(string file)
{
    ifstream input(file);
    if (input.is_open())
    {
        string line;
        while (getline(input, line))
        {
            body.append(line);
            body.append("\n");
        }
    }
    else
    {
        input.close();
        throw Failed_read_excption("can't read\nfilename:" + file);
    }
}