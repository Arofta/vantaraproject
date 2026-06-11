const {
    EmbedBuilder
} = require('discord.js');

module.exports = () => {

    return new EmbedBuilder()
        .setTitle('Vantara Legacy | Account Recovery')
        .setDescription('Kami tidak dapat menemukan akun yang tertaut dengan discord milik anda.\n')
        .setColor('#FFD700')
        .setTimestamp();
};