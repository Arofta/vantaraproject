const {
    EmbedBuilder
} = require('discord.js');

module.exports = () => {

    return new EmbedBuilder()
        .setTitle('Vantara Legacy | Check Account')
        .setDescription('Terjadi kesalahan saat memproses permintaan anda.\n')
        .setColor('#FFD700')
        .setTimestamp();
};