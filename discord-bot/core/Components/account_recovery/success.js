const {
    EmbedBuilder
} = require('discord.js');

module.exports = (accountName, accountStatus, accountCode) => {

    return new EmbedBuilder()
        .setTitle('Vantara Legacy | Account Recovery')
        .setDescription(
            'Permintaan pemulihan akun mu berhasil diproses.\n\n' +
            '**Account Name**\n' + 
            `\`\`\`${accountName}\`\`\`\n` + 

            '**Status**\n' + 
            `\`\`\`${accountStatus}\`\`\`\n` + 

            '**Verification Code**\n' + 
            `\`\`\`${accountCode}\`\`\`\n`
        )
        .setColor('#FFD700')
        .setTimestamp();
};