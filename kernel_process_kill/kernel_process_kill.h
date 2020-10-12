#include <ntifs.h>
#include <ntstrsafe.h>
#include "ioctls.h"

typedef struct _DEVICE_EXTENSION
{
	PDEVICE_OBJECT pDevObj;
	UNICODE_STRING usDevName;
	UNICODE_STRING usSymbolName;
	PUCHAR buffer;
	ULONG file_length;
}DEVICE_EXTENSION, * PDEVICE_EXTENSION;

#define arraysize(p) (sizeof(p)/sizeof((p)[0]))
#define MAX_FILE_LENGTH 1024
#define DEVICE_NAME	L"\\Device\\ProcessTerminateDevice"
#define SYM_LINK_NAME L"\\??\\ProcessTerminateDevice"

VOID Unload(IN PDRIVER_OBJECT pDriverObject);						// ж������
NTSTATUS CreateDevice(IN PDRIVER_OBJECT pDriverObject);				// ��װ�豸��������
NTSTATUS DispatchRoutin(IN PDEVICE_OBJECT pDevObj, IN PIRP pIrp);	// ͨ����ǲ����
NTSTATUS DeviceIOControl(IN PDEVICE_OBJECT pDevObj, IN PIRP pIrp);	// IO���ƺ�������ring3ͨ�ţ�
NTSTATUS TerminateProcess(IN ULONG ProcessID);						// ���̽�������
NTSTATUS WipeFile(IN wchar_t* path);								// �ļ��������� 