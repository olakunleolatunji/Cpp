#include "linkedlist.h"
#include <iostream>
#include <iomanip>

using namespace std;

LinkedList::LinkedList(){
	front = nullptr;
	back = nullptr;
}

LinkedList::~LinkedList(){
	destroyList();
}

void LinkedList::appendNode(string passengerName, string SeatNo,
	string DeparturePort,string DestinationPort,string boardingGate,
	string Flighttime,string Flightdate,string FlightNo){
	NODE* node = new NODE(passengerName,SeatNo,DeparturePort,
		DestinationPort,boardingGate,Flighttime,
		Flightdate,FlightNo);

	if(front == nullptr){
		front = node;
		back = node;
	}
	else{
		back->next = node;
		node->previous = back;
		back = node;
	}
}

void LinkedList::displayNodes(){
	NODE* temp = front;
	while(temp != nullptr){
		cout << string(50, '-') << endl;
        cout << setw(30) << "ARIK AIRLINE" << endl;
        cout << setw(30) << "BOARDING PASS\n" << endl;

        cout << "PASSENGER NAME: " << temp->passengerName << right << setw(10) << "DATE:" << temp->Flightdate << endl;
        cout << "SOURCE PORT: " << temp->DeparturePort << right << setw(30) << "DESTINATION PORT:" << temp->DestinationPort << endl;
        cout << "BOARDING GATE: " << temp->boardingGate << right << setw(30) << "SEAT NO:" << temp->SeatNo << endl;
        cout << "FLIGHT TIME: " << temp->Flighttime << right << setw(30) << "FLIGHT NO:" << temp->FlightNo << "\n" <<endl;

        cout << setw(30) << "Have a safe trip" << endl;
		cout << string(50, '-') << endl;

		temp = temp->next;
	}
}

void LinkedList::destroyList(){
	NODE* temp = front;

	while(temp != nullptr){
		NODE* toDelete = temp;
		temp = temp->next;
		delete toDelete;
	}
	front = nullptr;
	back = nullptr;
}
