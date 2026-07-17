enum e_CinemaList
{
    CINEMA_LOGIN,
    CINEMA_SUCCESS_LOGIN
};

SetPlayerCinemaScene(playerid, e_CinemaList:cinema)
{
    switch(cinema)
    {
        case CINEMA_LOGIN:
        {
            TogglePlayerSpectating(playerid, true);
            SetPlayerCameraPos(playerid, 1462.1173, -866.3331, 54.9074);
            SetPlayerCameraLookAt(playerid, 1413.0206, -807.6183, 85.0669);
            // SetPlayerCameraPos(playerid, 1611.095092, -977.369201, 120.943870);
            // SetPlayerCameraLookAt(playerid, 1590.844604, -2051.629638, 120.943870);
            InterpolateCameraPos(playerid, 1462.1173, -866.3331, 54.9074, 1424.6195, -867.0735, 49.5979, 50000, CAMERA_MOVE);
            return 1;
        }
        case CINEMA_SUCCESS_LOGIN: // Yang ini bbelum
        {
            TogglePlayerSpectating(playerid, true);
            SetPlayerCameraPos(playerid, 1462.1173, -866.3331, 54.9074);
            SetPlayerCameraLookAt(playerid, 1413.0206, -807.6183, 85.0669);
            // SetPlayerCameraPos(playerid, 1611.095092, -977.369201, 120.943870);
            // SetPlayerCameraLookAt(playerid, 1590.844604, -2051.629638, 120.943870);
            InterpolateCameraPos(playerid, 1462.1173, -866.3331, 54.9074, 1424.6195, -867.0735, 49.5979, 50000, CAMERA_MOVE);
            return 1;
        }
    }
    return 1;
}