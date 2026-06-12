#include <YSI_Coding\y_timers>

ptask Update1S[1000]()
{
    if(pData[playerid][pLoggedIn] && pData[playerid][pSpawned])
    {
        pData[playerid][pHungerTime]--;
        pData[playerid][pThirstTime]--;
        pData[playerid][pStressTime]--;

        if(!pData[playerid][pInjured])
        {
            new Float:stressMultiplier = 1.0 + (pData[playerid][pStress] / 200.0);

            if(pData[playerid][pHungerTime] <= 0)
            {
                pData[playerid][pHunger] -= (1.33 * stressMultiplier);

                if(pData[playerid][pHunger] < 0.0)
                    pData[playerid][pHunger] = 0.0;

                pData[playerid][pHungerTime] = 120;
            }

            if(pData[playerid][pThirstTime] <= 0)
            {
                pData[playerid][pThirst] -= (1.67 * stressMultiplier);

                if(pData[playerid][pThirst] < 0.0)
                    pData[playerid][pThirst] = 0.0;

                pData[playerid][pThirstTime] = 90;
            }

            if(pData[playerid][pStressTime] <= 0)
            {
                if(pData[playerid][InRelaxingArea] != -1)
                {
                    // Nanti akan di-isi
                }
                else
                {
                    new Float:needLevel = (pData[playerid][pHunger] * 0.4) + (pData[playerid][pThirst] * 0.6);

                    if(needLevel > 75.0)
                        pData[playerid][pStress] += 0.25;
                    else if(needLevel > 50.0)
                        pData[playerid][pStress] += 0.50;
                    else if(needLevel > 25.0)
                        pData[playerid][pStress] += 1.00;
                    else
                        pData[playerid][pStress] += 2.00;

                    if(pData[playerid][pStress] > 100.0)
                        pData[playerid][pStress] = 100.0;
                }

                pData[playerid][pStressTime] = 150;
            }

            if(pData[playerid][pHunger] <= 0.0)
            {
                pData[playerid][pHunger] = 0.0;
                pData[playerid][pHealth] -= 2.25;
                GameTextForPlayer(playerid, "~r~Kamu Mulai Kehilangan Kesadaran~n~~y~Kamu Merasa Lapar", 1000, 1);
            }

            if(pData[playerid][pThirst] <= 0.0)
            {
                pData[playerid][pThirst] = 0.0;
                pData[playerid][pHealth] -= 5.25;
                GameTextForPlayer(playerid, "~r~Kamu Mulai Kehilangan Kesadaran~n~~y~Kamu Merasa Haus", 1000, 1);
            }

            if(pData[playerid][pStress] <= 0.0)
                pData[playerid][pStress] = 0.0;

            if(pData[playerid][pHunger] > 100.0)
                pData[playerid][pHunger] = 100.0;

            if(pData[playerid][pThirst] > 100.0)
                pData[playerid][pThirst] = 100.0;
            
        }
    }
    return 1;
}