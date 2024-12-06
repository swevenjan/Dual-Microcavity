#ifndef  ADDetectorConstruction_h
#define  ADDetectorConstruction_h 1


#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"
#include "ADConstants.hh"
#include <array>
#include <string>

class G4VPhysicalVolume;
class G4LogicalVolume;
class G4Material;
class G4GlobalMagFieldMessenger;


class ADDetectorConstruction : public G4VUserDetectorConstruction
{
public:
	ADDetectorConstruction();
	virtual ~ADDetectorConstruction();

	
	virtual G4VPhysicalVolume* Construct();

	//�õ�������LV
	  G4LogicalVolume* GetMeasureBoxLV() const;
	  G4VPhysicalVolume* GetMeasureBoxPV() const;
	  G4LogicalVolume* GetairLV()const;
	  G4LogicalVolume* GetjxLV1()const;
	  G4LogicalVolume* GetjxLV2()const;
	  G4LogicalVolume* GetjxLV3()const;
	  G4LogicalVolume* GetjxLV4()const;
	  G4LogicalVolume* GetjxLV5()const;
	  G4LogicalVolume* GetjxLV6()const;
	  G4LogicalVolume* GetjxLV7()const;
	  G4LogicalVolume* GetjxLV8()const;
	  G4LogicalVolume* GetjxLV9()const;
	  G4LogicalVolume* GetjxLV10()const;
	  G4LogicalVolume* GetjxLV11()const;
	  G4LogicalVolume* GetjxLV12()const;
	  G4LogicalVolume* GetjxLV13()const;
	  G4LogicalVolume* GetjxLV14()const;
	  G4LogicalVolume* GetjxLV15()const;
	  G4LogicalVolume* GetjxLV16()const;
	  G4LogicalVolume* GetjxLV17()const;
	  G4LogicalVolume* GetjxLV18()const;
	  G4LogicalVolume* GetjxLV19()const;
	  G4LogicalVolume* GetjxLV20()const;
	  G4LogicalVolume* GetjxLV21()const;
	  G4LogicalVolume* GetjxLV22()const;
	  G4LogicalVolume* GetjxLV23()const;
	  G4LogicalVolume* GetjxLV24()const;
	  G4LogicalVolume* GetjxLV25()const;
	  G4LogicalVolume* GetjxLV26()const;
	  G4LogicalVolume* GetjxLV27()const;
	  G4LogicalVolume* GetjxLV28()const;
	  G4LogicalVolume* GetjxLV29()const;
	  G4LogicalVolume* GetjxLV30()const;
	  G4LogicalVolume* GetjxLV31()const;
	  G4LogicalVolume* GetjxLV32()const;
	  G4LogicalVolume* GetjxLV33()const;
	  G4LogicalVolume* GetjxLV34()const;
	  G4LogicalVolume* GetjxLV35()const;
	  G4LogicalVolume* GetjxLV36()const;
	  G4LogicalVolume* GetjxLV37()const;
	  G4LogicalVolume* GetjxLV38()const;
	  G4LogicalVolume* GetjxLV39()const;
	  G4LogicalVolume* GetjxLV40()const;
	  

	 //�õ�������LV
	  G4LogicalVolume* GetNangBoxLV() const;
	 //�õ�logicBox�����ָ��
	  G4LogicalVolume** GetflogicBoxLV() const;
	  G4VPhysicalVolume** GetpvBoxPV() const;

	  //�õ�shanyuan��ָ��
	  G4LogicalVolume* GetshanyuanLV() const;
	  G4VPhysicalVolume* GetshanyuanPV() const;

	  //�õ�wangge��ָ��
	  G4LogicalVolume* GetfwanggeLV() const;

private:


	G4LogicalVolume* fMeasureBoxLV;
	G4VPhysicalVolume* fMeasureBoxPV;
	G4LogicalVolume* fNangBoxLV;
	G4LogicalVolume* flogicair;
	G4LogicalVolume* flogicjx1;
	G4LogicalVolume* flogicjx2;
	G4LogicalVolume* flogicjx3;
	G4LogicalVolume* flogicjx4;
	G4LogicalVolume* flogicjx5;
	G4LogicalVolume* flogicjx6;
	G4LogicalVolume* flogicjx7;
	G4LogicalVolume* flogicjx8;
	G4LogicalVolume* flogicjx9;
	G4LogicalVolume* flogicjx10;
	G4LogicalVolume* flogicjx11;
	G4LogicalVolume* flogicjx12;
	G4LogicalVolume* flogicjx13;
	G4LogicalVolume* flogicjx14;
	G4LogicalVolume* flogicjx15;
	G4LogicalVolume* flogicjx16;
	G4LogicalVolume* flogicjx17;
	G4LogicalVolume* flogicjx18;
	G4LogicalVolume* flogicjx19;
	G4LogicalVolume* flogicjx20;
	G4LogicalVolume* flogicjx21;
	G4LogicalVolume* flogicjx22;
	G4LogicalVolume* flogicjx23;
	G4LogicalVolume* flogicjx24;
	G4LogicalVolume* flogicjx25;
	G4LogicalVolume* flogicjx26;
	G4LogicalVolume* flogicjx27;
	G4LogicalVolume* flogicjx28;
	G4LogicalVolume* flogicjx29;
	G4LogicalVolume* flogicjx30;
	G4LogicalVolume* flogicjx31;
	G4LogicalVolume* flogicjx32;
	G4LogicalVolume* flogicjx33;
	G4LogicalVolume* flogicjx34;
	G4LogicalVolume* flogicjx35;
	G4LogicalVolume* flogicjx36;
	G4LogicalVolume* flogicjx37;
	G4LogicalVolume* flogicjx38;
	G4LogicalVolume* flogicjx39;
	G4LogicalVolume* flogicjx40;


	//ΪlogicBox�����ָ�� 
	G4LogicalVolume** flogicBoxLV;
	G4VPhysicalVolume** fpvBoxPV;

	G4LogicalVolume* fshanyuanLV;//ͳ��դԪ
	G4VPhysicalVolume* fshanyuanPV;
	G4LogicalVolume* fwanggelv;//ͳ������

	//��������
	std::array<G4String, kNofEmCell> solidboxName;
	std::array<G4String, kNofEmCell> logicboxName;
	std::array<G4String, kNofEmCell> pvboxName;
	std::array<G4String, kNofEmCell> bianhaoName;
	

	//xyz��������
	std::array<G4double, kNofEmCell> fXCel;
	std::array<G4double, kNofEmCell> fYCel;
	std::array<G4double, kNofEmCell> fZCel;
};

inline G4LogicalVolume* ADDetectorConstruction::GetMeasureBoxLV() const
{
	return fMeasureBoxLV;//�õ�ˮģ��
}
inline G4VPhysicalVolume* ADDetectorConstruction::GetMeasureBoxPV() const
{
	return fMeasureBoxPV;
}
inline  G4LogicalVolume* ADDetectorConstruction::GetNangBoxLV() const
{
	return fNangBoxLV;//�õ�������
}
inline  G4LogicalVolume** ADDetectorConstruction::GetflogicBoxLV() const
{
	return flogicBoxLV;//�õ�logicBox�����ָ��
}
inline  G4VPhysicalVolume** ADDetectorConstruction::GetpvBoxPV() const
{
	return fpvBoxPV;//�õ�logicBox�����ָ��
}
inline  G4LogicalVolume* ADDetectorConstruction::GetshanyuanLV() const
{
	return fshanyuanLV;//�õ�������
}
inline  G4VPhysicalVolume* ADDetectorConstruction::GetshanyuanPV() const
{
	return fshanyuanPV;//�õ�������
}
inline  G4LogicalVolume* ADDetectorConstruction::GetfwanggeLV() const
{
	return fwanggelv;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetairLV() const
{
	return flogicair;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV1() const
{
	return flogicjx1;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV2() const
{
	return flogicjx2;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV3() const
{
	return flogicjx3;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV4() const
{
	return flogicjx4;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV5() const
{
	return flogicjx5;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV6() const
{
	return flogicjx6;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV7() const
{
	return flogicjx7;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV8() const
{
	return flogicjx8;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV9() const
{
	return flogicjx9;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV10() const
{
	return flogicjx10;//�õ�������
}
inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV11() const
{
	return flogicjx11;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV12() const
{
	return flogicjx12;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV13() const
{
	return flogicjx13;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV14() const
{
	return flogicjx14;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV15() const
{
	return flogicjx15;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV16() const
{
	return flogicjx16;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV17() const
{
	return flogicjx17;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV18() const
{
	return flogicjx18;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV19() const
{
	return flogicjx19;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV20() const
{
	return flogicjx20;//�õ�������
}inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV21() const
{
	return flogicjx21;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV22() const
{
	return flogicjx22;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV23() const
{
	return flogicjx23;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV24() const
{
	return flogicjx24;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV25() const
{
	return flogicjx25;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV26() const
{
	return flogicjx26;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV27() const
{
	return flogicjx27;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV28() const
{
	return flogicjx28;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV29() const
{
	return flogicjx29;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV30() const
{
	return flogicjx30;//�õ�������
}inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV31() const
{
	return flogicjx31;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV32() const
{
	return flogicjx32;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV33() const
{
	return flogicjx33;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV34() const
{
	return flogicjx34;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV35() const
{
	return flogicjx35;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV36() const
{
	return flogicjx36;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV37() const
{
	return flogicjx37;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV38() const
{
	return flogicjx38;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV39() const
{
	return flogicjx39;//�õ�������
}

inline  G4LogicalVolume* ADDetectorConstruction::GetjxLV40() const
{
	return flogicjx40;//�õ�������
}


#endif // ! ADDetectorConstruction_h
