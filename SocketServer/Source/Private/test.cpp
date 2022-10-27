// Send / Recive
// 구조체 통신 연습
/*StData SendStData;
SendStData.ActorType = "Sphere";
SendStData.LocX = 299;
SendStData.LocY = 199;
SendStData.LocZ = 399;

int SendInt;
int SendIntLength = sizeof(SendStData);

SendInt = send(ClientSocket, (char*)&SendIntLength, sizeof(int), 0);
if (SendInt == SOCKET_ERROR)
{
	std::cout << "Send Error" << std::endl;
	exit(-1);
}

SendInt = send(ClientSocket, (char*)&SendStData, sizeof(StData), 0);
if (SendInt == SOCKET_ERROR)
{
	std::cout << "Send Error" << std::endl;
	exit(-1);
}*/