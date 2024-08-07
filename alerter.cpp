#include <iostream>
#include <cassert>

// Global variable to keep track of alert failures
int alertFailureCount = 0;

// Stub function to simulate network alert behavior
int networkAlertStub(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    // Simulate a failure for temperatures over a threshold
    if (celcius > 100.0) {  // Threshold for failure simulation
        return 500;  // not-ok
    }
    return 200;  // ok
}

// Function to convert Fahrenheit to Celsius and send an alert
void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // Increment the failure count for non-ok responses
        alertFailureCount += 1;
    }
}

// Test function to verify error handling
void testErrorHandling() {
    alertInCelcius(212.0);  // Should trigger failure (Celsius > 100)
    alertInCelcius(77.0);   // Should succeed (Celsius < 100)
    assert(alertFailureCount == 1);  // Expecting exactly one failure
}

int main() {
    testErrorHandling();
    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}
