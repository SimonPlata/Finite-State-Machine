/* Finite State Machine Implementation Example
 * Blink
 * 
 *          ┌─┐     
 *          │ │     
 *          ├─┤     
 *          └─┘     
 *           |      
 *           |      
 *     ┌───────────┐
 * +-->│State1     │---+
 * |   ├───────────┤   |
 * |   │Set LED Off│   |
 * |   │Count = 0  │   |
 * |   └───────────┘   |
 * |Count >= 500ms     |Count >= 500ms
 * |                   |
 * |   ┌───────────┐   |
 * +---│State2     │<--+
 *     ├───────────┤
 *     │Set LED On │
 *     │Count = 0  │
 *     └───────────┘
 *
 *
 * Notes:
 * Condition evaluation priority is determined by the order in the
 * evaluation sequence.
 * State actions should be short and non-blocking. Long or complex
 * actions should be subdivided into additional states or into a
 * sub-machine.
 * 
 * I/O scanning can be on-demand (each condition reads its I/O) or
 * snapshot-based (all I/O is read once at the beginning of the loop
 * and then frozen).
 * The scanning method impacts the evaluation priority of the conditions.
 *
 * Created 25-Sep-2024 by Simón Plata
 * Revised 25-Aug-2025 by Simón Plata
 * 
 */
 
#define LED1 13

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  fsm1_update();
  delay(100);
}


void fsm1_update() {
  enum fsm_states {
    state_0,
    state_1,
    state_2
  };

  static enum fsm_states state = state_0;
  static int8_t count;

  switch(state) {
    
    case state_0:  if(1) {
            state = state_1;
            count = 0;
            digitalWrite(LED1, HIGH);
          }
          break;
              
    case state_1:  if(count >= 5) {    // state_1 --> state_2 transition for Input rising edge
            state = state_2;
            count = 0;
            digitalWrite(LED1, LOW);
          }
          else {
            count = count + 1;
          }
          break;
              
    case state_2:  if(count >= 5) {    // state_2 --> state_1 transition for Input rising edge
            state = state_1;
            count = 0;
            digitalWrite(LED1, HIGH);
          }
          else {
            count = count + 1;
          }
          break;
  }
}
