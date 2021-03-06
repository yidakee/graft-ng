#include "router.h"
#include "graft_manager.h"

#include <iostream>

namespace graft {

    Status coap_test(const Router::vars_t&, const Input&, Context&, Output&)
    {
         std::cout << "blah" << std::endl;

         return Status::Ok;
    }

    void setCoapRouters(Manager& m)
    {
        Router coap_router("/coap");
        Router::Handler3 h3_test(coap_test, nullptr, nullptr);

        coap_router.addRoute("/test", METHOD_GET, h3_test);
        coap_router.addRoute("/test1", METHOD_GET, h3_test);
        coap_router.addRoute("/test2", METHOD_GET, h3_test);

	m.addRouter(coap_router);
    }
}
