#include <iostream>
#include <cassert>


int alertFailureCount = 0;


int networkAlertStub(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
 
    if (celcius > 200.0) {  
        return 500;  
    }
    return 200;  
}


void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        
        alertFailureCount += 1;
    }
}


void testErrorHandling() {
    alertInCelcius(212.0);  
    alertInCelcius(392.0);  
    assert(alertFailureCount == 1);  
}

int main() {
    testErrorHandling();
    std::cout << alertFailureCount << " alerts failed.\n";
    if (alertFailureCount == 0) {
        std::cout << "All is well.\n";
    } else {
        std::cout << "There were alert failures!\n";
    }
    return 0;
}
