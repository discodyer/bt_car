const int fixedspeedA=;//(0~255)
const int fixedspeedB=;
const int fixedspeedC=;
const int fixedspeedD=;

void wheelSpeedCaculater(int speedx,int speedy,int yaw)
{
    //先分析x轴向运动的速度，向右为正方向
    int VwA,VwB,VwC,VwD,a=,b=;
    int speedOmega=yaw*(a+b);
    
    //x
    VwA += -1 * speedx;
    VwB += speedx;
    VwC += -1 * speedx;
    VwD += speedx;

    //y
    VwA += speedy;
    VwB += speedy;
    VwC += speedy;
    VwD += speedy;

    //O
    VwA += speedOmega;
    VwB += -1 * speedOmega;
    VwC += speedOmega;
    VwD += -1 * speedOmega;

    
}