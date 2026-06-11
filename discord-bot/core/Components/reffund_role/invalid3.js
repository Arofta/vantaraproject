const {
    EmbedBuilder
} = require('discord.js');

module.exports = () => {

    return new EmbedBuilder()
        .setTitle('Vantara Legacy | Reffund Role')
        .setDescription('Terjadi kesalahan saat memproses permintaan anda.\n')
        .setColor('#FFD700')
        .setTimestamp();
};