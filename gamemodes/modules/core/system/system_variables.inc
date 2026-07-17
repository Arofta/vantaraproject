new tempVerify[MAX_PLAYERS] = -1;
new tempRecovery[MAX_PLAYERS] = -1;
new tempLoginAttempts[MAX_PLAYERS] = 3;

new tempCharName[MAX_PLAYERS][MAX_PLAYER_NAME];
new tempCharDOB[MAX_PLAYERS][11];
new tempCharHeight[MAX_PLAYERS] = 0;
new tempCharWeight[MAX_PLAYERS] = 0;
new tempCharGender[MAX_PLAYERS] = -1;
new tempCharOrigin[MAX_PLAYERS] = -1;
new tempCharDomicile[MAX_PLAYERS] = -1; // Karena 0 = Los Santos, 1 = San Fierro, 2 = Las Venturas

enum e_CharacterInfo
{
    CharID,
    CharName[MAX_PLAYER_NAME],
    CharMoney,
    CharBankMoney,
    CharLevel
};

new PlayerChar[MAX_PLAYERS][MAX_CHARACTERS][e_CharacterInfo];

enum e_JailData
{
    bool:IsJailed,
    JailTime,

    JailIssuer[MAX_PLAYER_NAME],
    JailReason[60],
    JailFined
};

new OJailData[MAX_PLAYERS][e_JailData];

new const GenderNames[][] = {
    "Tidak Diketahui",
    "Laki-Laki",
    "Perempuan"
};

enum e_JobList
{
    JOB_NONE,
    JOB_MINER,
};

new const JobNames[][] = {
    "Pengangguran",
    "Penambang"
};

enum e_FactionList
{
    FACTION_NONE,
    FACTION_POLICE,
    FACTION_PARAMEDIC,
    FACTION_GOVERNMENT,
};

new const FactionNames[][] = {
    "N/A",
    "Kepolisian",
    "Paramedis",
    "Pemerintah"
};

new const FacPoliceRankNames[][] = {
    "N/A",

    "BHARADA",
    "BHARATU",
    "BHARAKA",
    "BRIPDA",
    "BRIPTU",
    "BRIGPOL",
    "BRIPKA",
    "AIPDA",
    "AIPTU",
    "IPDA",
    "IPTU",
    "AKP",
    "KOMPOL",
    "AKBP",
    "KOMBESPOL",
    "BRIGJENPOL",
    "IRJENPOL"
};

new const AdminRankNames[][] = {
    "N/A",
    "Trial Admin",
    "Admin Junior",
    "Admin Senior",
    "Head Admin",
    "Management",
    "Executive",
    "Adipati"
};

new const VIPLevelNames[][] = {
    "N/A",
    "{CD7F32}Bronze"F_COLOR_WHITE"",
    "{C0C0C0}Silver"F_COLOR_WHITE"",
    "{FFD700}Gold"F_COLOR_WHITE"",
    "{E5E4E2}Platinum"F_COLOR_WHITE"",
    "{5A0F0F}Eternium"F_COLOR_WHITE""
};

new const rand_MaleSkin[] = {
    2, 3, 7, 20,
    59, 147, 186, 
    249
};

new const rand_FemaleSkin[] = {
    56, 93, 169,
    193, 226, 233
};

new const CountryNames[][] = { // WAJIB BACA: Variabel ini tidak boleh dirubah, atau akan menyebabkan kesalahan pada origin player yang sudah daftar. (karena origin disimpan dalam bentuk index untuk meningkatkan performa)
    "Indonesia",
    "United States of America",
    "United Kingdom",
    "Afghanistan",
    "Albania",
    "Algeria",
    "Andorra",
    "Angola",
    "Antigua and Barbuda",
    "Argentina",
    "Armenia",
    "Australia",
    "Austria",
    "Azerbaijan",
    "Bahamas",
    "Bahrain",
    "Bangladesh",
    "Barbados",
    "Belarus",
    "Belgium",
    "Belize",
    "Benin",
    "Bhutan",
    "Bolivia",
    "Bosnia and Herzegovina",
    "Botswana",
    "Brazil",
    "Brunei Darussalam",
    "Bulgaria",
    "Burkina Faso",
    "Burundi",
    "Cabo Verde",
    "Cambodia",
    "Cameroon",
    "Canada",
    "Central African",
    "Chad",
    "Chile",
    "China",
    "Colombia",
    "Comoros",
    "Congo",
    "Congo",
    "Costa Rica",
    "Cote de Ivoire",
    "Croatia",
    "Cuba",
    "Cyprus",
    "Czech",
    "Denmark",
    "Djibouti",
    "Dominica",
    "Dominican",
    "Ecuador",
    "Egypt",
    "El Salvador",
    "Equatorial Guinea",
    "Eritrea",
    "Estonia",
    "Eswatini",
    "Ethiopia",
    "Fiji",
    "Finland",
    "France",
    "Gabon",
    "Gambia",
    "Georgia",
    "Germany",
    "Ghana",
    "Greece",
    "Grenada",
    "Guatemala",
    "Guinea",
    "Guinea Bissau",
    "Guyana",
    "Haiti",
    "Holy See (Vatican)",
    "Honduras",
    "Hungary",
    "Iceland",
    "India",
    "Iran",
    "Iraq",
    "Ireland",
    "Israel",
    "Italy",
    "Jamaica",
    "Japan",
    "Jordan",
    "Kazakhstan",
    "Kenya",
    "Kiribati",
    "North Korea",
    "South Korea",
    "Kuwait",
    "Kyrgyzstan",
    "Laos",
    "Latvia",
    "Lebanon",
    "Lesotho",
    "Liberia",
    "Libya",
    "Liechtenstein",
    "Lithuania",
    "Luxembourg",
    "Madagascar",
    "Malawi",
    "Malaysia",
    "Maldives",
    "Mali",
    "Malta",
    "Marshall Islands",
    "Mauritania",
    "Mauritius",
    "Mexico",
    "Micronesia",
    "Moldova",
    "Monaco",
    "Mongolia",
    "Montenegro",
    "Morocco",
    "Mozambique",
    "Myanmar",
    "Namibia",
    "Nauru",
    "Nepal",
    "Netherlands",
    "New Zealand",
    "Nicaragua",
    "Niger",
    "Nigeria",
    "North Macedonia",
    "Norway",
    "Oman",
    "Pakistan",
    "Palau",
    "Palestine",
    "Panama",
    "Papua New Guinea",
    "Paraguay",
    "Peru",
    "Philippines",
    "Poland",
    "Portugal",
    "Qatar",
    "Romania",
    "Russian Federation",
    "Rwanda",
    "Saint Kitts and Nevis",
    "Saint Lucia",
    "Saint Vincent and the Grenadines",
    "Samoa",
    "San Marino",
    "Sao Tome and Principe",
    "Saudi Arabia",
    "Senegal",
    "Serbia",
    "Seychelles",
    "Sierra Leone",
    "Singapore",
    "Slovakia",
    "Slovenia",
    "Solomon Islands",
    "Somalia",
    "South Africa",
    "South Sudan",
    "Spain",
    "Sri Lanka",
    "Sudan",
    "Suriname",
    "Sweden",
    "Switzerland",
    "Syrian Arab Republic",
    "Tajikistan",
    "Tanzania",
    "Thailand",
    "Timor-Leste",
    "Togo",
    "Tonga",
    "Trinidad and Tobago",
    "Tunisia",
    "Turkey",
    "Turkmenistan",
    "Tuvalu",
    "Uganda",
    "Ukraine",
    "United Arab Emirates",
    "Uruguay",
    "Uzbekistan",
    "Vanuatu",
    "Venezuela",
    "Vietnam",
    "Yemen",
    "Zambia",
    "Zimbabwe"
};

new const VehicleNames[][] =
{
	"Landstalker", "Bravura", "Buffalo", "Linerunner", "Pereniel", "Sentinel", "Dumper", "Firetruck", "Trashmaster", 
	"Stretch", "Manana", "Infernus", "Voodoo", "Pony", "Mule", "Cheetah", "Ambulance", "Leviathan", "Moonbeam", 
	"Esperanto", "Taxi", "Washington", "Bobcat", "Mr Whoopee", "BF Injection", "Hunter", "Premier", "Enforcer", 
	"Securicar", "Banshee", "Predator", "Bus", "Rhino", "Barracks", "Hotknife", "Trailer", "Previon", "Coach", 
	"Cabbie", "Stallion", "Rumpo", "RC Bandit", "Romero", "Packer", "Monster", "Admiral", "Squalo", "Seasparrow",
	"Pizzaboy", "Tram", "Trailer", "Turismo", "Speeder", "Reefer", "Tropic", "Flatbed", "Yankee", "Caddy", "Solair", 
	"Berkley's RC Van", "Skimmer", "PCJ-600", "Faggio", "Freeway", "RC Baron", "RC Raider", "Glendale", "Oceanic", 
	"Sanchez", "Sparrow", "Patriot", "Quad", "Coastguard", "Dinghy", "Hermes", "Sabre", "Rustler", "ZR-350", "Walton", 
	"Regina", "Comet", "BMX", "Burrito", "Camper", "Marquis", "Baggage", "Dozer", "Maverick", "News Chopper", "Rancher", 
	"FBI Rancher", "Virgo", "Greenwood", "Jetmax", "Hotring", "Sandking", "Blista", "Police Maverick", 
	"Boxville", "Benson", "Mesa", "RC Goblin", "Hotring-Racer", "Hotring-Racer", "Bloodring-Banger", "Rancher", 
	"Super-GT", "Elegant", "Journey", "Bike", "Mountain Bike", "Beagle", "Cropdust", "Stunt", "Tanker", "RoadTrain", 
	"Nebula", "Majestic", "Buccaneer", "Shamal", "Hydra", "FCR-900", "NRG-500", "HPV1000", "Cement Truck", "Tow Truck", 
	"Fortune", "Cadrona", "FBI Truck", "Willard", "Forklift", "Tractor", "Combine", "Feltzer", "Remington", "Slamvan", 
	"Blade", "Freight", "Streak", "Vortex", "Vincent", "Bullet", "Clover", "Sadler", "Firetruck", "Hustler", "Intruder", 
	"Primo", "Cargobob", "Tampa", "Sunrise", "Merit", "Utility", "Nevada", "Yosemite", "Windsor", "Monster Truck A", "Monster Truck B", 
	"Uranus", "Jester", "Sultan", "Stratum", "Elegy", "Raindance", "RC Tiger", "Flash", "Tahoma", "Savanna", "Bandito", 
	"Freight", "Trailer", "Kart", "Mower", "Duneride", "Sweeper", "Broadway", "Tornado", "AT-400", "DFT-30", 
	"Huntley", "Stafford", "BF-400", "Newsvan", "Tug", "Trailer", "Emperor", "Wayfarer", "Euros", "Hotdog", "Club", 
	"Trailer", "Trailer", "Andromada", "Dodo", "RC Cam", "Launch", "LSPD Car", "SFPD Car", "LVPD Car", 
	"Police Ranger", "Picador", "S.W.A.T. Van", "Alpha", "Phoenix", "Glendale", "Sadler", "Luggage Trailer", "Luggage Trailer", "Stair Trailer", 
	"Boxville", "Farm Plow", "Utility Trailer"
};