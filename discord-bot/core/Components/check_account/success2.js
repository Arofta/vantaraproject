const {
    EmbedBuilder
} = require('discord.js');

module.exports = (accountName, accountStatus, codeName, accountCode) => {

    return new EmbedBuilder()
        .setTitle('Vantara Legacy | Check Account')
        .setDescription(
            'Informasi akun berhasil ditemukan.\n\n' +
            '**Account Name**\n' + 
            `\`\`\`${accountName}\`\`\`\n` + 

            '**Status**\n' + 
            `\`\`\`${accountStatus}\`\`\`\n`
        )
        .setColor('#FFD700')
        .setTimestamp();
};