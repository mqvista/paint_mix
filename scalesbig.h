#ifndef SCALESBIG_H
#define SCALESBIG_H

#include <scales.h>


class ScalesBig : public Scales
{
    public:
        ScalesBig();

    private:
        void serialStrConver2Data(QString msg);
};

#endif // SCALESBIG_H
