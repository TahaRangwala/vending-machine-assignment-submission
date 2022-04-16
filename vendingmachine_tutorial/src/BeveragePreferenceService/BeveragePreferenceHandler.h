#ifndef VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER__H
#define VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER__H

#include <iostream>
#include <string>
#include <regex>
#include <future>

#include "../../gen-cpp/BeveragePreferenceService.h"

#include "../ClientPool.h"
#include "../ThriftClient.h"
#include "../logger.h"

namespace vending_machine{

class BeveragePreferenceServiceHandler : public BeveragePreferenceServiceIf {
 public:
  BeveragePreferenceServiceHandler();
  ~BeveragePreferenceServiceHandler() override=default;

  void getBeverage(std::string& _return, BeverageType::type btype) override;
};

// Constructor
BeveragePreferenceServiceHandler::BeveragePreferenceServiceHandler() {

}

//gets the beverage name
void BeveragePreferenceServiceHandler::getBeverage(std::string& _return, BeverageType::type btype){
        if(btype == BeverageType::type::HOT){
                int randomNum = rand()%3;
                if(randomNum == 0){
                        _return = "cappuccino";
                }
                else if(randomNum == 1){
                        _return = "latte";
                }
                else{
                        _return = "espresso";
                }
        }
        else{
                int randomNum = rand()%3;
                if(randomNum == 0){
                        _return = "lemonade";
                }
                else if(randomNum == 1){
                        _return = "ice tea";
                }
                else{
                        _return = "soda";
                }
        }
}

} // namespace vending_machine


#endif //VENDING_MACHINE_BEVERAGEPREFERENCEHANDLER_H
