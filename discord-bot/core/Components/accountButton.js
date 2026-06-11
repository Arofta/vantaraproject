const {
    ActionRowBuilder,
    ButtonBuilder,
    ButtonStyle
} = require('discord.js');

module.exports = () => {

    return new ActionRowBuilder()
        .addComponents(

            new ButtonBuilder()
                .setCustomId('create_account')
                .setLabel('Create Account')
                .setEmoji('➕')
                .setStyle(ButtonStyle.Success),

            new ButtonBuilder()
                .setCustomId('check_account')
                .setLabel('Check Account')
                .setEmoji('🔍')
                .setStyle(ButtonStyle.Primary),
            
            new ButtonBuilder()
                .setCustomId('account_recovery')
                .setLabel('Account Recovery')
                .setEmoji('🔐')
                .setStyle(ButtonStyle.Danger), 

            new ButtonBuilder()
                .setCustomId('reffund_role')
                .setLabel('Reffund Role')
                .setEmoji('♻️')
                .setStyle(ButtonStyle.Secondary)
                
        );
    
};