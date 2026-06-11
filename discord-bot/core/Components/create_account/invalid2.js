const {
    EmbedBuilder
} = require('discord.js');

module.exports = (accountName) => {

    return new EmbedBuilder()
        .setTitle('Vantara Legacy | Create Account')
        .setDescription(`Akun dengan nama \`${accountName}\` sudah digunakan oleh pemain lain.\n`)
        .setColor('#FFD700')
        .setTimestamp();
};
