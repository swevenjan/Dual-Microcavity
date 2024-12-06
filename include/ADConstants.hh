#ifndef ADConstants_h
#define ADConstants_h 1

#include "globals.hh"
#include "G4SystemOfUnits.hh"
//�ܹ���Ҫ����ͳ��ģ����� ��Ӧstep event
constexpr G4int kNofEmCel = 25;

//�ܹ���Ҫ����ͳ��ģ����� ��Ӧdc
constexpr G4int kNofEmCell = 25;
//ÿ�Ÿ���
constexpr G4int kNofEmRow = 5;

//ע��դ�� 1mm*1mm*1mm ��1000��

constexpr G4int layerThickness = 5 * mm;

//ΪСդԪ�ĸ���
constexpr G4int kNofEmCells = 1000;
//ÿ�����
constexpr G4int kNofEmRows = 100;

#endif
