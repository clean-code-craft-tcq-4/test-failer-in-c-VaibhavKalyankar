#include <stdio.h>
#include <assert.h>
#include "alerter.h"

int alertFailureCount = 0;
void TestAlertFailureCount();

int networkAlertStub(float celcius) {
    
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    if(celcius <= THRESHOLD_CELCIUS)
        return OK;
    else
        return NOT_OK;
}

#if(PRODUCTION_ENABLED != PRODUCTION_MODE_ON)
void TesteralertinCelcius(float Celcius,int ReturnCode)
{
    assert(Celcius<ReturnCode);
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
#if(PRODUCTION_ENABLED == PRODUCTION_MODE_ON)
    if (returnCode != 200) 
    {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount++;
    }
#else
    TesteralertinCelcius(celcius,returnCode);
#endif
}

void TestAlertFailureCount()
{
    alertInCelcius(600.0f);
    assert(alertFailureCount == 1);
    alertInCelcius(450.0f);
     assert(alertFailureCount == 2);
}
    
    

int main() {
    alertInCelcius(400.5);
    assert(alertFailureCount +1 == 1);
    alertInCelcius(303.6);
    assert(alertFailureCount == 0);
    TestAlertFailureCount();
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
