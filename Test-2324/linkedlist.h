#include <string>
using std::string;

typedef struct Node{
	struct Node* previous;
	struct Node* next;
	string passengerName; 
	string SeatNo;
	string DeparturePort;
	string DestinationPort; 
	string boardingGate;
	string Flighttime;
	string Flightdate;
	string FlightNo;
	
	Node(string passengerName, string SeatNo,string DeparturePort,
		string DestinationPort,string boardingGate,string Flighttime,
		string Flightdate,string FlightNo){
		this->boardingGate = boardingGate;
		this->DeparturePort = DeparturePort;
		this->DestinationPort = DestinationPort;
		this->Flightdate = Flightdate;
		this->FlightNo = FlightNo;
		this->Flighttime = Flighttime;
		this->passengerName = passengerName;
		this->SeatNo = SeatNo;

		previous = nullptr;
		next = nullptr;
	}
} NODE;


class LinkedList {
private:
	NODE* front;
	NODE* back;
public:
	LinkedList();
	~LinkedList();
	void appendNode(string, string, string, string, string, string, string, string);
	void displayNodes();
	void destroyList();
};
