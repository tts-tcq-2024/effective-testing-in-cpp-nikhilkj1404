#include <iostream>
#include <assert.h>

int alertFailureCount = 0;


int networkAlertStub(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    // Return 200 for ok
    // Return 500 for not-ok

    return (celcius > 200) ? 500 : 200;
}


void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        
        alertFailureCount += 1;
    }
}

int main() {
    
    alertInCelcius(400.5);  
    alertInCelcius(303.6);  

    
    assert(alertFailureCount == 1); 

    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}
