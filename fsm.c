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
 * Created 25-Sep-2024 by Simón Plata
 * Updated 26-Aug-2025 by Simón Plata
 *
 */
 
 
void fsm_update() {
	static int state = start;

	general_io_scanning_snapshot();
	
	switch(state) {
		case start:			state = state_0;
							fsm_setup();
							break;
		
		case state_0:		state_0_io_scanning_snapshot();
							if(state_0_condition_0) {
								state = state_0_condition_0_next_state;
								state_0_condition_0_next_state_action();
							}
							else if(state_0_condition_1) {
								state = state_0_condition_1_next_state;
								state_0_condition_1_next_state_action();
							}
							else if(state_0_condition_n) {
								state = state_0_condition_n_next_state;
								state_0_condition_n_next_state_action();
							}
							else {
								state = same_state;
								no_action();
							}
							break;
							
		case state_1:		state_1_io_scanning_snapshot();
							if(state_1_condition_0) {
								state = state_1_condition_0_next_state;
								state_1_condition_0_next_state_action();
							}
							else if(state_1_condition_1) {
								state = state_1_condition_1_next_state;
								state_1_condition_1_next_state_action();
							}
							else if(state_1_condition_n) {
								state = state_1_condition_n_next_state;
								state_1_condition_n_next_state_action();
							}
							else {
								state = same_state;
								no_action();
							}
							break;
							
		case state_n:		state_n_io_scanning_snapshot();
							if(state_n_condition_0) {
								state = state_n_condition_0_next_state;
								state_n_condition_0_next_state_action();
							}
							else if(state_n_condition_1) {
								state = state_n_condition_1_next_state;
								state_n_condition_1_next_state_action();
							}
							else if(state_n_condition_n) {
								state = state_n_condition_n_next_state;
								state_n_condition_n_next_state_action();
							}
							else {
								state = same_state;
								no_action();
							}
							break;
							
		default:			state = start;
							unknown_state_action();
							break;
	}
