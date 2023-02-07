/*
 * OccupancyDetector.c
 *
 *  Created on: Jan 30, 2023
 *      Author: Jaric Abadinas
 */

#include <msp430.h>


#define ARMED_STATE 0
#define WARNING_STATE 1
#define ALERT_STATE 2


int main() {
    // Put some initialization here
    P6DIR |= BIT6;              // Configure P6.6 to an Output

    P4DIR &= ~BIT1;             // Configure Pin 4.1 to an input
    P4REN |= BIT1;              // Enable the pull up/down resistor for Pin 4.1
    P4OUT |= BIT1;              // While configured as an input, P4OUT controls whether
                                // the resistor is a pull up or pull down

    P2DIR &= ~BIT3;             // Configure Pin 2.3 to an input
    P2REN |= BIT3;              // Enable the pull up/down resistor for Pin 2.3
    P2OUT |= BIT3;              // While configured as an input, P4OUT controls whether
                                // the resistor is a pull up or pull down

    PM5CTL0 &= ~LOCKLPM5;       // Disable the GPIO power-on default high-impedance mode
                                // to activate previously configured port settings

    char state = ARMED_STATE;

    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer

    while(1)
    {
      switch (state) {
        case ARMED_STATE:    //(~P4IN & BIT1) == if P4.1 is pressed
       {
           // Do something in the ARMED state
           // If something happens, you can move into the WARNING_STATE
           // state = WARNING_STATE
           if (~P2IN & BIT3)
               state == WARNING_STATE;
           else {
            P1OUT &= BIT0 == 0;              // Toggle off P1.0
            P6OUT &= BIT6 == 1;              // Toggle on P6.6
            __delay_cycles(500000);          // Delay for 100000*(1/MCLK)= 0.5s
            P6OUT &= BIT6 == 0;              // Toggle off P6.6
            __delay_cycles(3000000);         // Delay for 100000*(1/MCLK)= 3s
           }
        }
        case WARNING_STATE:
        {
            // Do something in the WARNING_STATE
            if (~P2IN & BIT3 && )
                state == ALERT_STATE;
            else if (~P2IN & BIT3 && ) {
            P6OUT &= BIT6 == 0;              // Toggle off P6.6
            P1OUT ^= BIT0;                   // Blink P1.0
            __delay_cycles(500000);          // Delay for 100000*(1/MCLK)= 0.5s
            }
        }
        case ALERT_STATE:
        {
            // Do something in the ALERT_STATE
            if (~P4IN & BIT1)
                state == ARMED_STATE;
            else
                P1OUT &= BIT0 == 1;              // Toggle on P6.6
        }
        }
      }
    }
}

