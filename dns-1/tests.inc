#include <cassert>

/* 
 *  "using namespace std", "sstream", and "string" defined
 *  in common.h
 */

bool st = false;
int  cnt = -1;
ostringstream os_expected;
ostringstream os_actual;

CZone z0 ( "fit.cvut.cz" );
st = z0 . Add ( CRecA ( "progtest", CIPv4 ( "147.32.232.142" ) ) ); // st = true
assert (st);
st = z0 . Add ( CRecAAAA ( "progtest", CIPv6 ( "2001:718:2:2902:0:1:2:3" ) ) ); // st = true
assert (st);
st = z0 . Add ( CRecA ( "edux", CIPv4 ( "147.32.232.158" ) ) ); // st = true
assert (st);
st = z0 . Add ( CRecA ( "edux", CIPv4 ( "147.32.232.160" ) ) ); // st = true
assert (st);
st = z0 . Add ( CRecA ( "edux", CIPv4 ( "147.32.232.159" ) ) ); // st = true
assert (st);
st = z0 . Add ( CRecAAAA ( "progtest", CIPv6 ( "2001:718:2:2902:1:2:3:4" ) ) ); // st = true
assert (st);
st = z0 . Add ( CRecMX ( "edux", "relay.fit.cvut.cz.", 0 ) ); // st = true
assert (st);
st = z0 . Add ( CRecMX ( "edux", "relay2.fit.cvut.cz.", 10 ) ); // st = true
assert (st);

cout << z0;
os_actual << z0;
os_expected.str(string("fit.cvut.cz\n") +
 string(" +- progtest A 147.32.232.142\n") +
 string( " +- progtest AAAA 2001:718:2:2902:0:1:2:3\n" )+
 string(" +- edux A 147.32.232.158\n")+
 string(" +- edux A 147.32.232.160\n")+
 string(" +- edux A 147.32.232.159\n")+
 string(" +- progtest AAAA 2001:718:2:2902:1:2:3:4\n")+
 string(" +- edux MX 0 relay.fit.cvut.cz.\n")+
 " \\- edux MX 10 relay2.fit.cvut.cz.\n");
assert (os_expected.str() == os_actual.str());
os_actual.clear();
os_actual.str("");
os_expected.clear();
os_expected.str("");
/*
--8<----8<----8<----8<----8<----8<----8<--
fit.cvut.cz
 +- progtest A 147.32.232.142
 +- progtest AAAA 2001:718:2:2902:0:1:2:3
 +- edux A 147.32.232.158
 +- edux A 147.32.232.160
 +- edux A 147.32.232.159
 +- progtest AAAA 2001:718:2:2902:1:2:3:4
 +- edux MX 0 relay.fit.cvut.cz.
 \- edux MX 10 relay2.fit.cvut.cz.
--8<----8<----8<----8<----8<----8<----8<--
*/
cnt = z0 . Search ( "progtest" ) . Count (); // cnt = 3
assert (cnt == 3);
cout << z0 . Search ( "progtest" );
os_actual << z0 . Search ( "progtest" );
os_expected.str( string("progtest A 147.32.232.142\n") +
	string("progtest AAAA 2001:718:2:2902:0:1:2:3\n")+
	string("progtest AAAA 2001:718:2:2902:1:2:3:4\n")
	);
assert (os_actual.str() == os_expected.str());

os_actual.clear();
os_actual.str("");
os_expected.clear();
os_expected.str("");
/*
--8<----8<----8<----8<----8<----8<----8<--
progtest A 147.32.232.142
progtest AAAA 2001:718:2:2902:0:1:2:3
progtest AAAA 2001:718:2:2902:1:2:3:4
--8<----8<----8<----8<----8<----8<----8<--
*/

st = z0 . Del ( CRecA ( "edux", CIPv4 ( "147.32.232.160" ) ) ); // st = true
assert (st);
st = z0 . Add ( CRecA ( "edux", CIPv4 ( "147.32.232.122" ) ) ); // st = true
assert (st);
cout << z0;
os_actual << z0;
os_expected.str(
string("fit.cvut.cz\n") +
string(" +- progtest A 147.32.232.142\n") +
string(" +- progtest AAAA 2001:718:2:2902:0:1:2:3\n")+
string(" +- edux A 147.32.232.158\n")+
string(" +- edux A 147.32.232.159\n")+
string(" +- progtest AAAA 2001:718:2:2902:1:2:3:4\n")+
string(" +- edux MX 0 relay.fit.cvut.cz.\n")+
string(" +- edux MX 10 relay2.fit.cvut.cz.\n")+
string(" \\- edux A 147.32.232.122\n")
	);
assert (os_actual.str() == os_expected.str());

os_actual.clear();
os_actual.str("");
os_expected.clear();
os_expected.str("");
/*
--8<----8<----8<----8<----8<----8<----8<--
fit.cvut.cz
 +- progtest A 147.32.232.142
 +- progtest AAAA 2001:718:2:2902:0:1:2:3
 +- edux A 147.32.232.158
 +- edux A 147.32.232.159
 +- progtest AAAA 2001:718:2:2902:1:2:3:4
 +- edux MX 0 relay.fit.cvut.cz.
 +- edux MX 10 relay2.fit.cvut.cz.
 \- edux A 147.32.232.122
--8<----8<----8<----8<----8<----8<----8<--
*/
cnt = z0 . Search ( "edux" ) . Count (); // cnt = 5
assert (cnt == 5);
cout << z0 . Search ( "edux" );
os_actual << z0 . Search ( "edux" );
os_expected.str(
string("edux A 147.32.232.158\n") +
string("edux A 147.32.232.159\n") +
string("edux MX 0 relay.fit.cvut.cz.\n")+
string("edux MX 10 relay2.fit.cvut.cz.\n")+
string("edux A 147.32.232.122\n")
	);
assert (os_actual.str() == os_expected.str());

os_actual.clear();
os_actual.str("");
os_expected.clear();
os_expected.str("");
/*
--8<----8<----8<----8<----8<----8<----8<--
edux A 147.32.232.158
edux A 147.32.232.159
edux MX 0 relay.fit.cvut.cz.
edux MX 10 relay2.fit.cvut.cz.
edux A 147.32.232.122
--8<----8<----8<----8<----8<----8<----8<--
*/

cout << z0 . Search ( "edux" ) [ 0 ];
os_actual << z0 . Search ( "edux" )[ 0 ];
os_expected.str("edux A 147.32.232.158\n");
assert (os_actual.str() == os_expected.str());
os_actual.clear();
os_actual.str("");
os_expected.clear();
os_expected.str("");
 // edux A 147.32.232.158


cout << z0  . Search ( "edux" ) [ 0 ] . Name () << endl;
 // edux
os_actual << z0 . Search ( "edux" )[ 0 ].Name() << endl;
os_expected.str("edux\n");
assert (os_actual.str() == os_expected.str());
os_actual.clear();
os_actual.str("");
os_expected.clear();
os_expected.str("");

cout << z0 . Search ( "edux" ) [ 0 ] . Type () << endl;
 // A
os_actual << z0 . Search ( "edux" )[ 0 ].Type() << endl;
os_expected.str("A\n");
assert (os_actual.str() == os_expected.str());
os_actual.clear();
os_actual.str("");
os_expected.clear();
os_expected.str("");


cout << z0 . Search ( "edux" ) [ 1 ];
 // edux A 147.32.232.159
os_actual << z0 . Search ( "edux" )[ 1 ];
os_expected.str("edux A 147.32.232.159\n");
assert (os_actual.str() == os_expected.str());
os_actual.clear();
os_actual.str("");
os_expected.clear();
os_expected.str("");

cout << z0  . Search ( "edux" ) [ 1 ] . Name () << endl;
 // edux
os_actual << z0 . Search ( "edux" )[ 1 ].Name() << endl;
os_expected.str("edux\n");
assert (os_actual.str() == os_expected.str());
os_actual.clear();
os_actual.str("");
os_expected.clear();
os_expected.str("");

cout << z0 . Search ( "edux" ) [ 1 ] . Type () << endl;
 // A
os_actual << z0 . Search ( "edux" )[ 1 ].Type() << endl;
os_expected.str("A\n");
assert (os_actual.str() == os_expected.str());
os_actual.clear();
os_actual.str("");
os_expected.clear();
os_expected.str("");


cout << z0 . Search ( "edux" ) [ 2 ];
 // edux MX 0 relay.fit.cvut.cz.
os_actual << z0 . Search ( "edux" )[ 2 ];
os_expected.str("edux MX 0 relay.fit.cvut.cz.\n");
assert (os_actual.str() == os_expected.str());
os_actual.clear();
os_actual.str("");
os_expected.clear();
os_expected.str("");


cout << z0  . Search ( "edux" ) [ 2 ] . Name () << endl;
 // edux
os_actual << z0 . Search ( "edux" )[ 2 ].Name() << endl;
os_expected.str("edux\n");
assert (os_actual.str() == os_expected.str());
os_actual.clear();
os_actual.str("");
os_expected.clear();
os_expected.str("");

cout << z0 . Search ( "edux" ) [ 2 ] . Type () << endl;
 // MX
os_actual << z0 . Search ( "edux" )[ 2 ].Type() << endl;
os_expected.str("MX\n");
assert (os_actual.str() == os_expected.str());
os_actual.clear();
os_actual.str("");
os_expected.clear();
os_expected.str("");

bool thrown = false;
try
{
	cout << z0 . Search ( "edux" ) [ 10 ];
	 // exception thrown
}
catch (InvalidIndexException &e)
{
	cout << e << endl;
	thrown = true;
}
assert (thrown);


CZone z2 ( "fit.cvut.cz" );
st = z2 . Add ( CRecA ( "progtest", CIPv4 ( "147.32.232.142" ) ) ); // st = true
assert (st);
st = z2 . Add ( CRecAAAA ( "progtest", CIPv6 ( "2001:718:2:2902:0:1:2:3" ) ) ); // st = true
assert (st);
st = z2 . Add ( CRecA ( "progtest", CIPv4 ( "147.32.232.144" ) ) ); // st = true
assert (st);
st = z2 . Add ( CRecMX ( "progtest", "relay.fit.cvut.cz.", 10 ) ); // st = true
assert (st);
st = z2 . Add ( CRecA ( "progtest", CIPv4 ( "147.32.232.142" ) ) ); // st = false
assert (!st);
st = z2 . Del ( CRecA ( "progtest", CIPv4 ( "147.32.232.140" ) ) ); // st = false
assert (!st);
st = z2 . Del ( CRecA ( "progtest", CIPv4 ( "147.32.232.142" ) ) ); // st = true
assert (st);
st = z2 . Del ( CRecA ( "progtest", CIPv4 ( "147.32.232.142" ) ) ); // st = false
assert (!st);
st = z2 . Add ( CRecMX ( "progtest", "relay.fit.cvut.cz.", 20 ) ); // st = true
assert (st);
st = z2 . Add ( CRecMX ( "progtest", "relay.fit.cvut.cz.", 10 ) ); // st = false
assert (!st);


cout << z2;
/*
--8<----8<----8<----8<----8<----8<----8<--
fit.cvut.cz
 +- progtest AAAA 2001:718:2:2902:0:1:2:3
 +- progtest A 147.32.232.144
 +- progtest MX 10 relay.fit.cvut.cz.
 \- progtest MX 20 relay.fit.cvut.cz.
--8<----8<----8<----8<----8<----8<----8<--
*/
os_actual << z2;
os_expected.str(
string("fit.cvut.cz") +
string(" +- progtest AAAA 2001:718:2:2902:0:1:2:3\n") +
string(" +- progtest A 147.32.232.144\n")+
string(" +- progtest MX 10 relay.fit.cvut.cz.\n")+
string(" \\- progtest MX 20 relay.fit.cvut.cz.\n")
	);
assert (os_actual.str() == os_expected.str());

os_actual.clear();
os_actual.str("");
os_expected.clear();
os_expected.str("");

cnt = z2 . Search ( "progtest" ) . Count (); // cnt = 4
assert (cnt == 4);


cout << z2 . Search ( "progtest" );
/*
--8<----8<----8<----8<----8<----8<----8<--
progtest AAAA 2001:718:2:2902:0:1:2:3
progtest A 147.32.232.144
progtest MX 10 relay.fit.cvut.cz.
progtest MX 20 relay.fit.cvut.cz.
--8<----8<----8<----8<----8<----8<----8<--
*/
os_actual << z2 . Search ( "progtest" );
os_expected.str(
string("progtest AAAA 2001:718:2:2902:0:1:2:3") +
string("progtest A 147.32.232.144") +
string("progtest MX 10 relay.fit.cvut.cz.")+
string("progtest MX 20 relay.fit.cvut.cz.")
	);
assert (os_actual.str() == os_expected.str());

os_actual.clear();
os_actual.str("");
os_expected.clear();
os_expected.str("");



cnt = z2 . Search ( "edux" ) . Count (); // cnt = 0
assert (cnt == 0);
cout << z2 . Search ( "edux" );
/*
--8<----8<----8<----8<----8<----8<----8<--
--8<----8<----8<----8<----8<----8<----8<--
*/
os_actual << z2 . Search ( "edux" );
// os_expected is already "" (blank string)
assert (os_actual.str() == os_expected.str());

os_actual.clear();
os_actual.str("");
os_expected.clear();
os_expected.str("");


CZone z4 ( "fit.cvut.cz" );
st = z4 . Add ( CRecA ( "progtest", CIPv4 ( "147.32.232.142" ) ) ); // st = true
assert (st);
st = z4 . Add ( CRecA ( "edux", CIPv4 ( "147.32.232.158" ) ) ); // st = true
assert (st);
st = z4 . Add ( CRecA ( "edux", CIPv4 ( "147.32.232.160" ) ) ); // st = true
assert (st);
st = z4 . Add ( CRecA ( "edux", CIPv4 ( "147.32.232.159" ) ) ); // st = true
assert (st);

CZone z5 ( z4 );
st = z4 . Add ( CRecAAAA ( "progtest", CIPv6 ( "2001:718:2:2902:0:1:2:3" ) ) ); // st = true
assert (st);
st = z4 . Add ( CRecAAAA ( "progtest", CIPv6 ( "2001:718:2:2902:1:2:3:4" ) ) ); // st = true
assert (st);
st = z5 . Del ( CRecA ( "progtest", CIPv4 ( "147.32.232.142" ) ) ); // st = true
assert (st);

cout << z4;
/*
--8<----8<----8<----8<----8<----8<----8<--
fit.cvut.cz
 +- progtest A 147.32.232.142
 +- edux A 147.32.232.158
 +- edux A 147.32.232.160
 +- edux A 147.32.232.159
 +- progtest AAAA 2001:718:2:2902:0:1:2:3
 \- progtest AAAA 2001:718:2:2902:1:2:3:4
--8<----8<----8<----8<----8<----8<----8<--
*/
os_actual << z4;
os_expected.str (
		string("fit.cvut.cz\n") +
		string(" +- progtest A 147.32.232.142\n") +
		string(" +- edux A 147.32.232.158\n") +
		string(" +- edux A 147.32.232.160\n") +
		string(" +- edux A 147.32.232.159\n") +
		string(" +- progtest AAAA 2001:718:2:2902:0:1:2:3\n") +
		string(" \\- progtest AAAA 2001:718:2:2902:1:2:3:4\n")	
	);
assert (os_actual.str() == os_expected.str());

os_actual.clear();
os_actual.str("");
os_expected.clear();
os_expected.str("");

cout << z5;
/*
--8<----8<----8<----8<----8<----8<----8<--
fit.cvut.cz
 +- edux A 147.32.232.158
 +- edux A 147.32.232.160
 \- edux A 147.32.232.159
--8<----8<----8<----8<----8<----8<----8<--
*/
os_actual << z5;
os_expected.str (
		string("fit.cvut.cz\n") +
		string(" +- edux A 147.32.232.158\n") +
		string(" +- edux A 147.32.232.160\n") +
		string(" \\- edux A 147.32.232.159\n") 
	);
assert (os_actual.str() == os_expected.str());

os_actual.clear();
os_actual.str("");
os_expected.clear();
os_expected.str("");

z5 = z4;
st = z4 . Add ( CRecMX ( "edux", "relay.fit.cvut.cz.", 0 ) ); // st = true
assert (st);
st = z4 . Add ( CRecMX ( "edux", "relay2.fit.cvut.cz.", 10 ) ); // st = true
assert (st);
cout << z4;
/*
--8<----8<----8<----8<----8<----8<----8<--
fit.cvut.cz
 +- progtest A 147.32.232.142
 +- edux A 147.32.232.158
 +- edux A 147.32.232.160
 +- edux A 147.32.232.159
 +- progtest AAAA 2001:718:2:2902:0:1:2:3
 +- progtest AAAA 2001:718:2:2902:1:2:3:4
 +- edux MX 0 relay.fit.cvut.cz.
 \- edux MX 10 relay2.fit.cvut.cz.
--8<----8<----8<----8<----8<----8<----8<--
*/
os_actual << z4;
os_expected.str (
		string("fit.cvut.cz\n") +
 string(" +- progtest A 147.32.232.142\n") +
 string(" +- edux A 147.32.232.158\n")+
 string(" +- edux A 147.32.232.160\n")+
 string(" +- edux A 147.32.232.159\n")+
 string(" +- progtest AAAA 2001:718:2:2902:0:1:2:3\n")+
 string(" +- progtest AAAA 2001:718:2:2902:1:2:3:4\n")+
 string(" +- edux MX 0 relay.fit.cvut.cz.\n")+
 string(" \\- edux MX 10 relay2.fit.cvut.cz.\n")
	);
assert (os_actual.str() == os_expected.str());

os_actual.clear();
os_actual.str("");
os_expected.clear();
os_expected.str("");

cout << z5;
/*
--8<----8<----8<----8<----8<----8<----8<--
fit.cvut.cz
 +- progtest A 147.32.232.142
 +- edux A 147.32.232.158
 +- edux A 147.32.232.160
 +- edux A 147.32.232.159
 +- progtest AAAA 2001:718:2:2902:0:1:2:3
 \- progtest AAAA 2001:718:2:2902:1:2:3:4
--8<----8<----8<----8<----8<----8<----8<--
*/

os_actual << z5;
os_expected.str (
		string("fit.cvut.cz\n") +
 string(" +- progtest A 147.32.232.142\n") +
 string(" +- edux A 147.32.232.158\n")+
 string(" +- edux A 147.32.232.160\n")+
 string(" +- edux A 147.32.232.159\n")+
 string(" +- progtest AAAA 2001:718:2:2902:0:1:2:3\n")+
 string(" \\- progtest AAAA 2001:718:2:2902:1:2:3:4\n")
	);
assert (os_actual.str() == os_expected.str());

os_actual.clear();
os_actual.str("");
os_expected.clear();
os_expected.str("");
