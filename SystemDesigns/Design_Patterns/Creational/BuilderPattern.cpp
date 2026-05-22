#include<iostream>
using namespace std;

class HttpBuilder;

class HttpRequest{

    private:

        string url;
        string header = "";
        string method = "GET";
        string body = "";
        int port;

        HttpRequest() = default;

        friend class HttpBuilder;

    public:
        void send(){

            cout << "Sending " << method << " to url " << url << " at Port : " << port << ", Body : " << body << endl;
        }

};

class HttpBuilder{

    private:

    HttpRequest request;

    public:

    HttpBuilder& setUrl(string url){
        
        request.url = url;
        return *this; 
    }

    HttpBuilder& setHeader(string headers){
        
        request.header = headers;
        return *this;   // method chaining
    }

    HttpBuilder& setMethod(string method){
        
        request.method = method;
        return *this; 
    }

    HttpBuilder& setBody(string body){
        
        request.body = body;
        return *this; 
    }

    HttpBuilder& setPort(int port){
        request.port = port;
        return *this;
    }

    HttpRequest build(){
        return request;
    }

};

int main(){

    HttpRequest req = HttpBuilder()
                        .setPort(200)
                        .setHeader("type/json")
                        .setUrl("Google.com")
                        .setBody("HTML")
                        .build();

    req.send();

    return 0;

}