#include <YSI_Coding\y_timers>

ptask UpdateHBE[1000](playerid)
{
    if(pData[playerid][pLoggedIn] && pData[playerid][pSpawned])
    {
        if(!pData[playerid][pInjured] && !OJailData[playerid][IsJailed])
        {
            new Float:stressMultiplier = 1.0 + (pData[playerid][pStress] / 120.0);

            if(++pData[playerid][pHungerTime] >= 120)
            {
                if(pData[playerid][pHunger] > 0.0)
                    pData[playerid][pHunger] -= (2.64 * stressMultiplier);

                pData[playerid][pHungerTime] = 0;
                if(pData[playerid][pHunger] <= 15.0)
                    GameTextForPlayer(playerid, "~y~Merasa Lapar", 7900, 1);
            }

            if(++pData[playerid][pThirstTime] >= 90)
            {
                if(pData[playerid][pThirst] > 0.0)
                    pData[playerid][pThirst] -= (2.33 * stressMultiplier);

                pData[playerid][pThirstTime] = 0;
                if(pData[playerid][pThirst] <= 15.0)
                    GameTextForPlayer(playerid, "~y~Merasa Haus", 7900, 1);
            }

            if(++pData[playerid][pStressTime] >= 150)
            {
                if(pData[playerid][InRelaxingArea] != -1)
                {
                    // Nanti akan di-isi
                }
                else
                {
                    new Float:needLevel = (pData[playerid][pHunger] * 0.4) + (pData[playerid][pThirst] * 0.6);
                    if(pData[playerid][pStress] < 100.0)
                    {
                        if(needLevel > 75.0)
                            pData[playerid][pStress] += 0.25;
                        else if(needLevel > 50.0)
                            pData[playerid][pStress] += 0.50;
                        else if(needLevel > 25.0)
                            pData[playerid][pStress] += 1.00;
                        else
                            pData[playerid][pStress] += 2.00;
                    }
                }

                pData[playerid][pStressTime] = 0;
            }
        }

        if(pData[playerid][pHunger] <= 0.0)
        {
            pData[playerid][pHunger] = 0.0;
            if(!pData[playerid][pInjured])
            {
                pData[playerid][pHealth] -= 2.25;
                if(++pData[playerid][pInjuryWarn] >= 8)
                {
                    GameTextForPlayer(playerid, "~r~Mulai Kehilangan Kesadaran~n~~y~Merasa Lapar", 7900, 1);
                    pData[playerid][pInjuryWarn] = 0;
                }
            }
        }

        if(pData[playerid][pThirst] <= 0.0)
        {
            pData[playerid][pThirst] = 0.0;
            if(!pData[playerid][pInjured])
            {
                pData[playerid][pHealth] -= 5.25;
                if(++pData[playerid][pInjuryWarn] >= 8)
                {
                    GameTextForPlayer(playerid, "~r~Mulai Kehilangan Kesadaran~n~~y~Merasa Haus", 7900, 1);
                    pData[playerid][pInjuryWarn] = 0;
                }
            }
        }

        if(pData[playerid][pStress] < 0.0)
            pData[playerid][pStress] = 0.0;

        if(pData[playerid][pHunger] > 100.0)
            pData[playerid][pHunger] = 100.0;

        if(pData[playerid][pThirst] > 100.0)
            pData[playerid][pThirst] = 100.0;

        if(pData[playerid][pStress] > 100.0)
            pData[playerid][pStress] = 100.0;

        if(TDInfo[playerid][HBETDShown])
        {
            PlayerTextDrawSetString(playerid, HBEPTD[playerid][0], "%.0f", pData[playerid][pHunger]);
            PlayerTextDrawSetString(playerid, HBEPTD[playerid][1], "%.0f", pData[playerid][pThirst]);
            PlayerTextDrawSetString(playerid, HBEPTD[playerid][2], "%.0f", pData[playerid][pStress]);
        }

        SetPlayerHealth(playerid, pData[playerid][pHealth]);
        SetPlayerArmour(playerid, pData[playerid][pArmour]);

    }
    return 1;
}

ptask UpdateActivity[1000](playerid)
{
    if(pData[playerid][pLoggedIn] && pData[playerid][pSpawned])
    {
        pData[playerid][pPlaytime]++;
    }
    return 1;
}

ptask UpdateInjuredTime[1000](playerid)
{
    if(pData[playerid][pInjured] && pData[playerid][pLoggedIn] && pData[playerid][pSpawned] && !OJailData[playerid][IsJailed])
    {
        if(pData[playerid][pInjuryTime] > 0)
        {
            pData[playerid][pInjuryTime]--;

            PlayerTextDrawSetString(playerid, InjuryPTD[playerid][0], "%02d", pData[playerid][pInjuryTime] % 60); // detik
            PlayerTextDrawSetString(playerid, InjuryPTD[playerid][1], "%02d", (pData[playerid][pInjuryTime] % 3600) / 60); // menit
            PlayerTextDrawSetString(playerid, InjuryPTD[playerid][2], "%02d", pData[playerid][pInjuryTime] / 3600); // jam

            SetPlayerHealth(playerid, 1000);
            ApplyAnimation(playerid, "WUZI", "CS_DEAD_GUY", 4.1, false, false, false, true, 0, SYNC_ALL);
            
            if(pData[playerid][pInjuryTime] > 3120)
                SetPlayerDrunkLevelEx(playerid, 3800);
            else
                SetPlayerDrunkLevelEx(playerid, 1200);
        }
        else
        {
            SendClientMessage(playerid, -1, "INFO: Karakter kamu mengalami koma akibat kehabisan banyak darah.");
            SetPlayerHealthEx(playerid, 42);
            pData[playerid][pInjured] = false;
            pData[playerid][pInjuryTime] = 0;
            pData[playerid][pHunger] = 50.0;
            pData[playerid][pThirst] = 50.0;
            pData[playerid][pStress] = 22.0;
            ClearAnimations(playerid);
        }
    }
    return 1;
}