const {
    EmbedBuilder
} = require('discord.js');

module.exports = () => {

    return new EmbedBuilder()
        .setTitle('Vantara Legacy | Reffund Role')
        .setDescription(`Permintaan gagal diproses, Kamu sudah memiliki role <@&${process.env.ROLE_WARGA}>\n`)
        .setColor('#FFD700')
        .setTimestamp();
};