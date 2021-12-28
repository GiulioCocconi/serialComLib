#include "SerialComLib.h"

SerialCom::SerialCom(Stream &port, char term, int delay) {
	_port = port;
	_term = term;
	_delay = delay;
}

void SerialCom::begin(int rate) {
	_port.begin(rate);
}

String SerialCom::send(String msg) {
	delay(_del);
	_port.print(msg + _term);
	String debug = "Messaggio inviato: " + msg;
	return debug;
}

String SerialCom::receive() {
	String msg = "";
	if (_port.available() > 0) {
		msg = _port.readStringUntil(_term);
	}
	return msg;
}

