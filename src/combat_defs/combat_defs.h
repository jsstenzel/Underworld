#import <combat_parser.h>

//A combat is a smaller game loop embedded in the larger one
//It uses its own parser, the BattleParser, with a restricted set of commands
//A combat goes back and forth, you and the enemy taking actions and updating the game state,
//until one of you dies or flees.


//implement pretty much like game loop: 
//run "fight.init_combat(); while(fight.combat_loop()) fight.parse(s)"
class EurynomosCombat : CombatParser
{ 

};
