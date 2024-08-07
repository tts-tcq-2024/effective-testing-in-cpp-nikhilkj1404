#include <iostream>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    // Simulate a failure for temperatures over a threshold
    if (celcius > 150.0) {
        return 500;  // not-ok
    }
    return 200;  // ok
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // Increment the failure count for non-ok responses
        alertFailureCount += 1;
    }
}

int main() {
    alertInCelcius(400.5);  // This should fail
    alertInCelcius(303.6);  // This should succeed
    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}
