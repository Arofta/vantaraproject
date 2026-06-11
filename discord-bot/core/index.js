const {
    Client,
    GatewayIntentBits
} = require('discord.js');

const path = require('path');

require('dotenv').config({
    path: path.join(__dirname, '../.env')
});

const loadEvents =
    require('./Handlers/eventHandler');

const client = new Client({
    intents: [
        GatewayIntentBits.Guilds,
        GatewayIntentBits.GuildMessages,
        GatewayIntentBits.MessageContent,
        GatewayIntentBits.GuildMembers
    ]
});

loadEvents(client);

client.once('clientReady', () => { 
  console.log(`Logged in as ${client.user.tag}`); 
}); 

client.login(process.env.TOKEN);