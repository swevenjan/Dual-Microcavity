#ifndef ADEventAction_h
#define ADEventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"
#include "ADConstants.hh"
#include <array>

class ADRunAction;


class ADEventAction :public G4UserEventAction
{
public:
	ADEventAction(ADRunAction* runAction);
	virtual ~ADEventAction();

	virtual void BeginOfEventAction(const G4Event* event);
	virtual void EndOfEventAction(const G4Event* event);
	
	//event方法：将此event的step对应的edep进行累加
	void AddEdep(G4double edep , int i) { fEdep[i] += edep; }
	void AddEdepair(G4double edep) { fEdepair += edep; }

private:
	
	
	

	ADRunAction* fRunAction;
	
	//event的edep数组，对应40个径向统计网格的沉积能量
	std::array<G4double,40> fEdep;
	G4double fEdepair;
	
};



#endif // !ADEventAction_h
