#include <iostream>
#include <cassert>


int alertFailureCount = 0;


int networkAlertStub(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";

    if (celcius > 100.0) {  
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
    alertInCelcius(77.0);   
    assert(alertFailureCount == 1);  
}

int main() {
    testErrorHandling();
    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}
