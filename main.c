/*
 
 C prime finder 
 syntax: 
 $ BINARY
    add 1000 primes to the prime log
 $ BINARY [number] 
    add [number] primes to the prime log
 $ BINARY [anything] [number]
    find all the primes between 1 and [number]
 
 
 C prime finder will find all prime numbers up to [number], then print out 
 computation time       primes          computation time/prime
 
Andrew Batz ||  @odinsven || @excenter
 2015
 
 */

#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
#include <stdbool.h>
#define PRIMESADDED 1000



bool returnPrimes(long long underTest);
long long int incrementUnderTest (long long oldTest);
long long int primeTracker (bool addOne);

int main(int argc, const char * argv[]) {
    //allow for test to value
    int testToValue = 0;
    int thisManyPrimes = 0;
    if (argc == 3) {
        testToValue = atoi(argv[2]);
    }
    
    if (argc == 2) {
        thisManyPrimes = atoi(argv[1]);
    }
    
    if (argc == 1) {
        thisManyPrimes = PRIMESADDED;
    }
    
    
    //write to primelog.txt
    
    
    // start the timer
    clock_t begin, end;
    double timeSpent;
    begin = clock();
    
    
    //printf("%lld\n",underTest );
    
    // if you set this monster loose, and let it find as many as it can. use control+C to quit.
    // area for improvement
    if (testToValue == 0) {
        
        // read the last line of primelog.txt
        FILE *fileBuffer, *writeBuffer;
        
        writeBuffer = fopen("primelog.txt", "a");
        
        long long int readFromFile = -1;
        fileBuffer = fopen("primelog.txt", "r");
        while (1) {
            if (!feof(fileBuffer)) {
                fscanf(fileBuffer, "%lld\n", &readFromFile);
                //            printf("I AM READING THE FILE");
                //            printf("%lld\n",readFromFile );
            }
            else{
                break;
            }
        }
        
        long long underTest;
        
        if (readFromFile == -1) {
            underTest = 1;
            //         printf("I DIDN'T READ THE FILE, STARTING @ 1");
        }
        else{
            underTest = incrementUnderTest(readFromFile);
            //        printf("%lld\n",readFromFile );
            //        printf("I READ THE FILE, STARTING @ above");
        }
        

        
        //printf("%lld\n",primeTracker(false) );
        
        while( (primeTracker(false)) < thisManyPrimes ){
        
            
            //printf("%lld\n",primeTracker(false) );
            
            //this spits the value to the screen, here it could save to file.
            if (returnPrimes(underTest)) {
                printf("%lld\n",underTest);
                fprintf(writeBuffer, "\n%lld",underTest);
            }
            
            
            // this is to avoid testing even numbers
            underTest = incrementUnderTest(underTest);
            
            
        }
        fclose(writeBuffer);
        fclose(fileBuffer);
    }
    
    else{
        long long int underTest =1;
        for (; underTest<= testToValue; underTest= incrementUnderTest(underTest)) {
            //this spits the value to the screen, here it could save to file.
            if (returnPrimes(underTest)) {
                printf("%lld\n",underTest);
            }

        }
    
    }
    
    // end the timer
    end = clock();
    timeSpent = (double) (end - begin) / CLOCKS_PER_SEC;
    
    printf("\n\n Time spent = %lf \t Primes = %lld \t Seconds/Prime = %f \n\n", timeSpent, primeTracker(false), timeSpent/primeTracker(false) );
    
    
    return 0;
}



long long int primeTracker (bool addOne){
    static long long int primes = 0;
    if (addOne) {
        primes++;
    }
    return primes;
}

long long int incrementUnderTest (long long oldTest){
    if (oldTest == 1 || oldTest == 2) {
        oldTest ++;
    }
    else{
        oldTest +=2;
    }
    return oldTest;
}

bool returnPrimes(long long underTest){
    bool couldBePrime = true;
    for (long long i=2; i<(underTest/2); i++) {
        long long remainder;
        remainder = underTest%i;
        if (remainder ==0) {
            // try passing straight false to the function that calls it.
            return false;
            // or switch the candidate position to false and escape the loop. passing the false through the "official channel"
            couldBePrime = false;
            break;
        }
    }
    primeTracker(true);
    
    return couldBePrime;
}
