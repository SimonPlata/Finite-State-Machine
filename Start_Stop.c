/* Finite State Machine Implementation Example
 * Start Stop
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
 * |   └───────────┘   |
 * |Stop               |Start && !Stop
 * |                   |
 * |   ┌───────────┐   |
 * +---│State2     │<--+
 *     ├───────────┤
 *     │Set LED On │
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
 
void fsm_update() {
 enum fsm_states {
    state_0,
    state_1,
    state_2
  };
  
  static enum fsm_states state = state_0;
  int8_t Start;
  int8_t Stop;
  
  Start = !digitalRead(PushButton1);
  Stop  = !digitalRead(PushButton2);
  switch(state) {
    
    case state_0:  if(1) {
            state = state_1;
            digitalWrite(LED, LOW);
          }
          break;
              
    case state_1:  if((Start == HIGH) && !(Stop == HIGH)) {    // state_1 --> state_2 transition
            state = state_2;
            digitalWrite(LED, HIGH);
          }
          break;
              
    case state_2:  if(Stop == HIGH) {    // state_2 --> state_1 transition
            state = state_1;
            digitalWrite(LED, LOW);
          }
          break;
  }
}
