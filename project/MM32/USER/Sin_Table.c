#include "sys.h"
//------------------------------------------------------------------------------

const int16_t s16SinTable[]={ // SINE  Index  Angle  
     0 ,   201 ,   402 ,   603 ,   804 ,  1006 ,  1207 ,  1408 ,  1609 ,  1810 ,
  2011 ,  2212 ,  2412 ,  2613 ,  2814 ,  3014 ,  3214 ,  3415 ,  3615 ,  3815 ,
  4015 ,  4214 ,  4414 ,  4613 ,  4812 ,  5011 ,  5210 ,  5409 ,  5607 ,  5805 ,
  6003 ,  6201 ,  6398 ,  6596 ,  6793 ,  6989 ,  7186 ,  7382 ,  7578 ,  7774 ,
  7969 ,  8164 ,  8359 ,  8553 ,  8747 ,  8941 ,  9135 ,  9328 ,  9521 ,  9713 ,
  9905 , 10097 , 10288 , 10479 , 10669 , 10859 , 11049 , 11238 , 11427 , 11616 ,
 11804 , 11991 , 12178 , 12365 , 12551 , 12737 , 12922 , 13106 , 13291 , 13474 ,
 13658 , 13840 , 14022 , 14204 , 14385 , 14566 , 14746 , 14925 , 15104 , 15282 ,
 15460 , 15637 , 15814 , 15990 , 16165 , 16340 , 16514 , 16688 , 16860 , 17033 ,
 17204 , 17375 , 17546 , 17715 , 17884 , 18052 , 18220 , 18387 , 18553 , 18719 ,
 18884 , 19048 , 19211 , 19374 , 19536 , 19697 , 19857 , 20017 , 20176 , 20334 ,
 20492 , 20648 , 20804 , 20959 , 21114 , 21267 , 21420 , 21572 , 21723 , 21873 ,
 22023 , 22171 , 22319 , 22466 , 22612 , 22757 , 22902 , 23045 , 23188 , 23330 ,
 23470 , 23610 , 23750 , 23888 , 24025 , 24161 , 24297 , 24432 , 24565 , 24698 ,
 24830 , 24961 , 25090 , 25219 , 25347 , 25475 , 25601 , 25726 , 25850 , 25973 ,
 26095 , 26217 , 26337 , 26456 , 26574 , 26692 , 26808 , 26923 , 27037 , 27150 ,
 27263 , 27374 , 27484 , 27593 , 27701 , 27808 , 27914 , 28019 , 28123 , 28225 ,
 28327 , 28428 , 28527 , 28626 , 28723 , 28819 , 28915 , 29009 , 29102 , 29194 ,
 29285 , 29374 , 29463 , 29550 , 29637 , 29722 , 29806 , 29889 , 29971 , 30052 ,
 30132 , 30210 , 30288 , 30364 , 30439 , 30513 , 30586 , 30657 , 30728 , 30797 ,
 30865 , 30932 , 30998 , 31063 , 31126 , 31189 , 31250 , 31310 , 31368 , 31426 ,
 31482 , 31538 , 31592 , 31644 , 31696 , 31747 , 31796 , 31844 , 31891 , 31936 ,
 31981 , 32024 , 32066 , 32107 , 32146 , 32185 , 32222 , 32258 , 32293 , 32326 ,
 32359 , 32390 , 32419 , 32448 , 32476 , 32502 , 32527 , 32550 , 32573 , 32594 ,
 32614 , 32633 , 32651 , 32667 , 32682 , 32696 , 32709 , 32720 , 32730 , 32739 ,
 32747 , 32754 , 32759 , 32763 , 32766 , 32767 , 32767 , 32767 , 32764 , 32761 ,
 32756 , 32750 , 32743 , 32735 , 32725 , 32715 , 32703 , 32689 , 32675 , 32659 ,
 32642 , 32624 , 32604 , 32584 , 32562 , 32539 , 32514 , 32489 , 32462 , 32434 ,
 32405 , 32374 , 32343 , 32310 , 32275 , 32240 , 32204 , 32166 , 32127 , 32087 ,
 32045 , 32003 , 31959 , 31914 , 31867 , 31820 , 31771 , 31721 , 31670 , 31618 ,
 31565 , 31510 , 31454 , 31397 , 31339 , 31280 , 31219 , 31157 , 31095 , 31031 ,
 30965 , 30899 , 30831 , 30763 , 30693 , 30622 , 30549 , 30476 , 30402 , 30326 ,
 30249 , 30171 , 30092 , 30012 , 29930 , 29848 , 29764 , 29680 , 29594 , 29507 ,
 29419 , 29330 , 29239 , 29148 , 29055 , 28962 , 28867 , 28771 , 28674 , 28577 ,
 28478 , 28377 , 28276 , 28174 , 28071 , 27966 , 27861 , 27755 , 27647 , 27538 ,
 27429 , 27318 , 27207 , 27094 , 26980 , 26866 , 26750 , 26633 , 26515 , 26397 ,
 26277 , 26156 , 26034 , 25912 , 25788 , 25663 , 25538 , 25411 , 25284 , 25155 ,
 25026 , 24895 , 24764 , 24632 , 24498 , 24364 , 24229 , 24093 , 23956 , 23819 ,
 23680 , 23541 , 23400 , 23259 , 23117 , 22973 , 22830 , 22685 , 22539 , 22393 ,
 22245 , 22097 , 21948 , 21798 , 21647 , 21496 , 21344 , 21191 , 21037 , 20882 ,
 20726 , 20570 , 20413 , 20255 , 20097 , 19937 , 19777 , 19616 , 19455 , 19293 ,
 19130 , 18966 , 18801 , 18636 , 18470 , 18304 , 18136 , 17968 , 17800 , 17630 ,
 17461 , 17290 , 17119 , 16947 , 16774 , 16601 , 16427 , 16253 , 16078 , 15902 ,
 15726 , 15549 , 15371 , 15193 , 15015 , 14835 , 14656 , 14475 , 14295 , 14113 ,
 13931 , 13749 , 13566 , 13383 , 13199 , 13014 , 12829 , 12644 , 12458 , 12271 ,
 12085 , 11897 , 11710 , 11521 , 11333 , 11144 , 10954 , 10764 , 10574 , 10383 ,
 10192 , 10001 ,  9809 ,  9617 ,  9424 ,  9231 ,  9038 ,  8844 ,  8650 ,  8456 ,
  8262 ,  8067 ,  7871 ,  7676 ,  7480 ,  7284 ,  7088 ,  6891 ,  6694 ,  6497 ,
  6300 ,  6102 ,  5904 ,  5706 ,  5508 ,  5309 ,  5111 ,  4912 ,  4713 ,  4513 ,
  4314 ,  4114 ,  3915 ,  3715 ,  3515 ,  3315 ,  3114 ,  2914 ,  2713 ,  2513 ,
  2312 ,  2111 ,  1910 ,  1709 ,  1508 ,  1307 ,  1106 ,   905 ,   704 ,   503 ,
   301 ,   100 ,  -100 ,  -301 ,  -503 ,  -704 ,  -905 , -1106 , -1307 , -1508 ,
 -1709 , -1910 , -2111 , -2312 , -2513 , -2713 , -2914 , -3114 , -3315 , -3515 ,
 -3715 , -3915 , -4114 , -4314 , -4513 , -4713 , -4912 , -5111 , -5309 , -5508 ,
 -5706 , -5904 , -6102 , -6300 , -6497 , -6694 , -6891 , -7088 , -7284 , -7480 ,
 -7676 , -7871 , -8067 , -8262 , -8456 , -8650 , -8844 , -9038 , -9231 , -9424 ,
 -9617 , -9809 ,-10001 ,-10192 ,-10383 ,-10574 ,-10764 ,-10954 ,-11144 ,-11333 ,
-11521 ,-11710 ,-11897 ,-12085 ,-12271 ,-12458 ,-12644 ,-12829 ,-13014 ,-13199 ,
-13383 ,-13566 ,-13749 ,-13931 ,-14113 ,-14295 ,-14475 ,-14656 ,-14835 ,-15015 ,
-15193 ,-15371 ,-15549 ,-15726 ,-15902 ,-16078 ,-16253 ,-16427 ,-16601 ,-16774 ,
-16947 ,-17119 ,-17290 ,-17461 ,-17630 ,-17800 ,-17968 ,-18136 ,-18304 ,-18470 ,
-18636 ,-18801 ,-18966 ,-19130 ,-19293 ,-19455 ,-19616 ,-19777 ,-19937 ,-20097 ,
-20255 ,-20413 ,-20570 ,-20726 ,-20882 ,-21037 ,-21191 ,-21344 ,-21496 ,-21647 ,
-21798 ,-21948 ,-22097 ,-22245 ,-22393 ,-22539 ,-22685 ,-22830 ,-22973 ,-23117 ,
-23259 ,-23400 ,-23541 ,-23680 ,-23819 ,-23956 ,-24093 ,-24229 ,-24364 ,-24498 ,
-24632 ,-24764 ,-24895 ,-25026 ,-25155 ,-25284 ,-25411 ,-25538 ,-25663 ,-25788 ,
-25912 ,-26034 ,-26156 ,-26277 ,-26397 ,-26515 ,-26633 ,-26750 ,-26866 ,-26980 ,
-27094 ,-27207 ,-27318 ,-27429 ,-27538 ,-27647 ,-27755 ,-27861 ,-27966 ,-28071 ,
-28174 ,-28276 ,-28377 ,-28478 ,-28577 ,-28674 ,-28771 ,-28867 ,-28962 ,-29055 ,
-29148 ,-29239 ,-29330 ,-29419 ,-29507 ,-29594 ,-29680 ,-29764 ,-29848 ,-29930 ,
-30012 ,-30092 ,-30171 ,-30249 ,-30326 ,-30402 ,-30476 ,-30549 ,-30622 ,-30693 ,
-30763 ,-30831 ,-30899 ,-30965 ,-31031 ,-31095 ,-31157 ,-31219 ,-31280 ,-31339 ,
-31397 ,-31454 ,-31510 ,-31565 ,-31618 ,-31670 ,-31721 ,-31771 ,-31820 ,-31867 ,
-31914 ,-31959 ,-32003 ,-32045 ,-32087 ,-32127 ,-32166 ,-32204 ,-32240 ,-32275 ,
-32310 ,-32343 ,-32374 ,-32405 ,-32434 ,-32462 ,-32489 ,-32514 ,-32539 ,-32562 ,
-32584 ,-32604 ,-32624 ,-32642 ,-32659 ,-32675 ,-32689 ,-32703 ,-32715 ,-32725 ,
-32735 ,-32743 ,-32750 ,-32756 ,-32761 ,-32764 ,-32767 ,-32767 ,-32767 ,-32766 ,
-32763 ,-32759 ,-32754 ,-32747 ,-32739 ,-32730 ,-32720 ,-32709 ,-32696 ,-32682 ,
-32667 ,-32651 ,-32633 ,-32614 ,-32594 ,-32573 ,-32550 ,-32527 ,-32502 ,-32476 ,
-32448 ,-32419 ,-32390 ,-32359 ,-32326 ,-32293 ,-32258 ,-32222 ,-32185 ,-32146 ,
-32107 ,-32066 ,-32024 ,-31981 ,-31936 ,-31891 ,-31844 ,-31796 ,-31747 ,-31696 ,
-31644 ,-31592 ,-31538 ,-31482 ,-31426 ,-31368 ,-31310 ,-31250 ,-31189 ,-31126 ,
-31063 ,-30998 ,-30932 ,-30865 ,-30797 ,-30728 ,-30657 ,-30586 ,-30513 ,-30439 ,
-30364 ,-30288 ,-30210 ,-30132 ,-30052 ,-29971 ,-29889 ,-29806 ,-29722 ,-29637 ,
-29550 ,-29463 ,-29374 ,-29285 ,-29194 ,-29102 ,-29009 ,-28915 ,-28819 ,-28723 ,
-28626 ,-28527 ,-28428 ,-28327 ,-28225 ,-28123 ,-28019 ,-27914 ,-27808 ,-27701 ,
-27593 ,-27484 ,-27374 ,-27263 ,-27150 ,-27037 ,-26923 ,-26808 ,-26692 ,-26574 ,
-26456 ,-26337 ,-26217 ,-26095 ,-25973 ,-25850 ,-25726 ,-25601 ,-25475 ,-25347 ,
-25219 ,-25090 ,-24961 ,-24830 ,-24698 ,-24565 ,-24432 ,-24297 ,-24161 ,-24025 ,
-23888 ,-23750 ,-23610 ,-23470 ,-23330 ,-23188 ,-23045 ,-22902 ,-22757 ,-22612 ,
-22466 ,-22319 ,-22171 ,-22023 ,-21873 ,-21723 ,-21572 ,-21420 ,-21267 ,-21114 ,
-20959 ,-20804 ,-20648 ,-20492 ,-20334 ,-20176 ,-20017 ,-19857 ,-19697 ,-19536 ,
-19374 ,-19211 ,-19048 ,-18884 ,-18719 ,-18553 ,-18387 ,-18220 ,-18052 ,-17884 ,
-17715 ,-17546 ,-17375 ,-17204 ,-17033 ,-16860 ,-16688 ,-16514 ,-16340 ,-16165 ,
-15990 ,-15814 ,-15637 ,-15460 ,-15282 ,-15104 ,-14925 ,-14746 ,-14566 ,-14385 ,
-14204 ,-14022 ,-13840 ,-13658 ,-13474 ,-13291 ,-13106 ,-12922 ,-12737 ,-12551 ,
-12365 ,-12178 ,-11991 ,-11804 ,-11616 ,-11427 ,-11238 ,-11049 ,-10859 ,-10669 ,
-10479 ,-10288 ,-10097 , -9905 , -9713 , -9521 , -9328 , -9135 , -8941 , -8747 ,
 -8553 , -8359 , -8164 , -7969 , -7774 , -7578 , -7382 , -7186 , -6989 , -6793 ,
 -6596 , -6398 , -6201 , -6003 , -5805 , -5607 , -5409 , -5210 , -5011 , -4812 ,
 -4613 , -4414 , -4214 , -4015 , -3815 , -3615 , -3415 , -3214 , -3014 , -2814 ,
 -2613 , -2412 , -2212 , -2011 , -1810 , -1609 , -1408 , -1207 , -1006 ,  -804 ,
  -603 ,  -402 ,  -201 ,     0  
};


//==============================================================================

int16_t Cos(uint16_t u16TableAddr)
{
		u16TableAddr += 256;
		if(u16TableAddr >= 1024)
		u16TableAddr -= 1024;

		return s16SinTable[u16TableAddr];
}

int16_t Sin(uint16_t u16TableAddr)
{
		if(u16TableAddr >= 1024)
		u16TableAddr -= 1024;
		return s16SinTable[u16TableAddr];
}

int16_t IPD_Sin(uint16_t u16TableAddr)
{
		if(u16TableAddr >= 511)
		u16TableAddr = 511;
		return s16SinTable[u16TableAddr];
}

int16_t Under_Over_16_cp(int16_t s16InputAngle)
{
		if     (s16InputAngle > 32767) s16InputAngle = s16InputAngle - 32768;
		else if(s16InputAngle < 0)     s16InputAngle = 0;//angle + 32768;
		else                      s16InputAngle = s16InputAngle;
		return s16InputAngle;    
} 

