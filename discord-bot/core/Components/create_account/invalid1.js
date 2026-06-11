const {
    EmbedBuilder
} = require('discord.js');

module.exports = () => {

    return new EmbedBuilder()
        .setTitle('Vantara Legacy | Create Account')
        .setDescription(
            'Nama akun hanya boleh mengandung huruf (A-Z) dan angka (0-9).\n\n' +
            '**Contoh nama yang valid:**\n' +
            '`Arofta`\n' +
            '`Vantara`\n' +
            '`Player123`\n' +
            '`Arofta2026`\n'
        )
        .setColor('#FFD700')
        .setTimestamp();
};