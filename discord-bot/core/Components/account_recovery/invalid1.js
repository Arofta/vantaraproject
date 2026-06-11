const {
    EmbedBuilder
} = require('discord.js');

module.exports = (accountName, accountStatus, accountCode) => {

    return new EmbedBuilder()
        .setTitle('Vantara Legacy | Account Recovery')
        .setDescription(
            'Gagal memproses permintaan. Silakan verifikasi akun terlebih dahulu.\n\n' +
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