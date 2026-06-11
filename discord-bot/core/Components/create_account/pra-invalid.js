const {
    EmbedBuilder
} = require('discord.js');

module.exports = (accountName) => {

    return new EmbedBuilder()
        .setTitle('Vantara Legacy | Create Account')
        .setDescription(
            'Terdapat akun yang sudah terdaftar menggunakan discord ini, Kamu tidak dapat mendaftarkan akun dengan discord yang sama sebanyak 2x atau lebih.\n\n' +
            '**Account Name**\n' + 
            `\`\`\`${accountName}\`\`\`\n`
        )
        .setColor('#FFD700')
        .setTimestamp();
};