


#ifndef CHANGEPASSWARD_PRIVATE_H_
#define CHANGEPASSWARD_PRIVATE_H_

static void EEPROM_passwardRetrieval (u8 passward[], u16 passwardSize, u16 address);
static void EEPROM_KeyPad_passwardSave (u8 passward[], u16 passwardSize, u16 address);
static void EEPROM_KeyPad_Ctrigger ();



#endif /* CHANGEPASSWARD_PRIVATE_H_ */