#include<iostream>
using namespace std;
class handler{
    public:
    handler()
    {

    }

    virtual void handle_request(void) = 0;
    shared_ptr<handler> next_handler = nullptr;
};

class handler_A: public handler{
    public:
    handler_A(){
        
    }

    void handle_request(){
        std::cout << "inside the handle_request of A" << std::endl;
        bool forward = false;

        // business logic
        forward = true;

        // if the request is not in the scope forward
        if(next_handler && forward)
        {
            // forward the request
            next_handler->handle_request();
            return;
        }

        // resolved here
        return;
    };
};

class handler_B: public handler{
    public:
    handler_B(){
        
    }

    void handle_request(){
        std::cout << "inside the handle_request of B" << std::endl;
        bool forward = false;

        // business logic
        forward = true;

        // if the request is not in the scope forward
        if(next_handler && forward)
        {
            // forward the request
            next_handler->handle_request();
            return;
        }

        // resolved here
        return;
    }
};

class handler_C: public handler{
    public:
    handler_C(){
        
    }

    void handle_request(){
        std::cout << "inside the handle_request of A" << std::endl;
        bool forward = false;

        // business logic
        forward = true;

        // if the request is not in the scope forward
        if(next_handler && forward)
        {
            // forward the request
            next_handler->handle_request();
            return;
        }

        // resolved here
        return;
    }
};

int main(void)
{
    std::cout << "Begin chain of responsibility" << std::endl;

    // define the ptrs
    auto handler_a = make_shared<handler_A>();
    auto handler_b = make_shared<handler_B>();
    auto handler_c = make_shared<handler_C>();

    // define the chain
    handler_a->next_handler = handler_b;
    handler_b->next_handler = handler_c;

    // receive the request
    // mocked not implemented here
    

    // call first handler
    handler_a->handle_request();
}