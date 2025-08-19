/* Finite State Machine implementation template
 *
 * Notes:
 * Condition evaluation priority is defined by the position in the evaluation sequence.
 * State actions should short and not blocking. Long and complex actions should
 * be subdivided in additional states or in a sub-machine.
 * I/O scanning could be by demmand (every condition reads it I/O) or snapshot (All I/O
 * read at once at the begining of the loop and freeze). The scanning method has an
 * impact in the conditions evaluation priority.
 *
 * Created 25-Sep-2024
 * by Simón Plata
 *
 */
 
 
void fsm() {
	static int state = 0;
	
	switch(state) {
		case state_0:	s0_io_scanning_snapshot();
							if(state_0_condition_0) {
								state = next_state;
								next_state_action_0();
							}
							else if(state_0_condition_1) {
								state = next_state;
								next_state_action_1();
							}
							else if(state_0_condition_n) {
								state = next_state;
								next_state_action_n();
							}
							else {
								state = same_state;
								no_action();
							}
							break;
							
		case state_1:	s1_io_scanning_snapshot();
							if(state_1_condition_0) {
								state = next_state;
								next_state_action_0();
							}
							else if(state_1_condition_1) {
								state = next_state;
								next_state_action_1();
							}
							else if(state_1_condition_n) {
								state = next_state;
								next_state_action_n();
							}
							else {
								state = same_state;
								no_action();
							}
							break;
							
		case state_n:	sn_io_scanning_snapshot();
							if(state_n_condition_0) {
								state = next_state;
								next_state_action_0();
							}
							else if(state_n_condition_1) {
								state = next_state;
								next_state_action_1();
							}
							else if(state_n_condition_n) {
								state = next_state;
								next_state_action_n();
							}
							else {
								state = same_state;
								no_action();
							}
							break;
							
		defaul:		state = 0;
							unknown_state_action();
							break;
	}
