
#include <iostream>
using namespace std;


class Report {
public:
    virtual void generate() const = 0;
};

class TextReport : public Report {
public:
    void generate() {
        cout << "Ganerate text report: " << endl;
    }
};

    class PdfReport : public Report {
    public:
        void generate() {
            cout << "Gnerate pdf report: " << endl;
        }
    };

    class ExselReport : public Report {
    public:
        void generate() {
            cout << "Generate excel report: ";
        }
    };

    class ReportFactory {
    public:
        virtual Report* createReport() const = 0;

    };

    class TextReportFactory : public ReportFactory {
    public:
        Report* createReport() {
            return new TextReport();
        }
    };

    class PdfReportFactory : public ReportFactory {
    public:
        Report* createReport() {
            return new PdfReport();
        }
    };

    class ExselReporFactory : public ReportFactory {
    public:
        Report* createReport() {
            return new ExselReport();
        }
    };

    int main()
    {
        ReportFactory* factory = new PdfReportFactory();
        Report* report = factory->createReport();

        report->generate();

        delete factory;
        delete report;

        return 0;
    }

