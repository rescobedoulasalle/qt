//Author    :   Anil C S
//Website   :   www.technoburst.net

#include <iostream>
#include <QProcess>

using namespace std;

int main(int argc, char *argv[])
{
    cout<<"\n * Program to demonstrate the usage of linux commands in qt * \n";

    QProcess OProcess;
    QString Command;    //Contains the command to be executed
    QStringList args;   //Contains arguments of the command

    Command = "ls";
    args<<"-l"<<"/home/richart";

    OProcess.start(Command,args,QIODevice::ReadOnly); //Starts execution of command
    OProcess.waitForFinished();                       //Waits for execution to complete

    QString StdOut      =   OProcess.readAllStandardOutput();  //Reads standard output
    QString StdError    =   OProcess.readAllStandardError();   //Reads standard error

    cout<<"\n Printing the standard output..........\n";
    cout<<endl<<StdOut.toStdString();
    cout<<"\n Printing the standard error..........\n";
    cout<<endl<<StdError.toStdString();

    cout<<"\n\n";
    return 0;
}
