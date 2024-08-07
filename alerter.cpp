#include <iostream>
#include <assert.h>

int alertFailureCount = 0;


int networkAlertStub(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    // Return 200 for ok
    // Return 500 for not-ok
    
    return (celcius > 150) ? 500 : 200;
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
    alertInCelcius(100.0);  

    
    assert(alertFailureCount == 2); 

    if (alertFailureCount != 2) {
        std::cerr << "FALSE POSITIVE! Expected failure but succeeded\n";
    }

    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}
