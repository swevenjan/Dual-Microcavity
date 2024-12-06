#ifndef ADRunAction_h
#define ADRunAction_h 1

#include "G4UserRunAction.hh"
#include "globals.hh"
#include "G4Accumulable.hh"
#include "ADConstants.hh"
#include <array>
#include <vector>
class G4Run;

class ADRunAction : public G4UserRunAction
{
public:
	ADRunAction();
	virtual ~ADRunAction();

	virtual void BeginOfRunAction(const G4Run*);
	virtual void EndOfRunAction(const G4Run*);
	
	//run��������event��edep����ͳ��10��
	void AddEdep(G4double edep, int i) { fEdep[i] += edep; };

	void AddEdeair(G4double edep) { fEdepair += edep; };
	//run������SDר��

	//����ӦդԪ��edep�������Ӧ����
	void AddMeaBoxEdep( G4double edep,G4int i);//����ӦդԪ��edep�������Ӧ����
	// ��1000��դԪ�������ܺ�
	void AddTotalEdep(G4double edep);//��1000��դԪ�������ܺ�
	//������Ӽ������
	void AddTotalEdep_meabox(G4double edep);
	//�������������
	void AddTotalEdep_nangbox(G4double edep);
	//�Ҽ������
	void AddTotalEdep_nang(G4double edep);
	//��ǻ�������
	void AddTotalEdep_waiqiang(G4double edep);
	//��ǻ�������
	void AddTotalEdep_neiqiang(G4double edep);

private:
	
	//ͳ��step��ʽ��run edep���� ��Ӧ40jx��ͳ������

	std::array <G4double, 40> fEdep;
	G4double fEdepair;

	//G4Accumulable<G4double>
	/*std::vector<G4Accumulable<G4double>> fEdep;*/


    ////G4Accumulable<G4double>  ɾ��
	//std::vector<G4Accumulable<G4double>> MeaBoxTotalEdep;//1000��hits������������¼

	//ͳ��SD��ʽ��run edep���� ��Ӧ1000��ͳ������

	std::array<G4double, kNofEmCells> MeaBoxTotalEdep;//1000��hits������������¼
	G4double TotalEdep;//1000��СդԪ�ܵĳ�������

	G4Accumulable<G4double> Edep_shanyuan;//G4Accumulable  դԪ�ܵĳ�������
	G4Accumulable<G4double> Edep_meabox;//G4Accumulable  ��������ܵĳ�������
	G4Accumulable<G4double> Edep_nangbox;//G4Accumulable  �������ܵĳ�������
	G4Accumulable<G4double> Edep_nang;//G4Accumulable  ���ܵĳ�������
	G4Accumulable<G4double> Edep_waiqiang;//G4Accumulable  ��ǻ�ܵĳ�������
	G4Accumulable<G4double> Edep_neiqiang;//G4Accumulable  ��ǻ�ܵĳ�������

	G4double TotalEdep_meabox;//��������ܵĳ�������
	G4double TotalEdep_nangbox;//�������ܵĳ�������
	G4double TotalEdep_nang;//���ܵĳ�������
	G4double TotalEdep_waiqiang;//��ǻ�ܵĳ�������
    G4double TotalEdep_neiqiang;//��ǻ�ܵĳ�������

	G4double fMeaBoxMass;//СդԪ�������
};

inline void ADRunAction::AddMeaBoxEdep( G4double edep,G4int i)
{
	MeaBoxTotalEdep[i] += edep;
}

inline void ADRunAction::AddTotalEdep(G4double edep)
{

	TotalEdep += edep;
	Edep_shanyuan += edep;
}

//������Ӽ������
inline void ADRunAction::AddTotalEdep_meabox(G4double edep)
{
	TotalEdep_meabox += edep;
	Edep_meabox += edep;
}
//�������������
inline void ADRunAction::AddTotalEdep_nangbox(G4double edep)
{
	TotalEdep_nangbox += edep;
	Edep_nangbox += edep;
}
//�Ҽ������
inline void ADRunAction::AddTotalEdep_nang(G4double edep)
{
	TotalEdep_nang += edep;
	Edep_nang += edep;
}
//��ǻ�������
inline void ADRunAction::AddTotalEdep_waiqiang(G4double edep)
{
	TotalEdep_waiqiang += edep;
	Edep_waiqiang += edep;
}
//��ǻ�������
inline void ADRunAction::AddTotalEdep_neiqiang(G4double edep)
{
	TotalEdep_neiqiang += edep;
	Edep_neiqiang += edep;
}
#endif // !ADRunAction_h
