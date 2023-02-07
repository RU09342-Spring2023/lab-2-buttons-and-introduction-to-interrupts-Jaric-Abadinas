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

// Put some initialization here

    char state = ARMED_STATE;

int main() {
    while(1)
    {
      switch (state) {
        case ARMED_STATE:
        {
          // Do something in the ARMED state
          // If something happens, you can move into the WARNING_STATE
          // state = WARNING_STATE
        }
        case WARNING_STATE:
        {
          // Do something in the WARNING_STATE
        }
      }
    }
}

