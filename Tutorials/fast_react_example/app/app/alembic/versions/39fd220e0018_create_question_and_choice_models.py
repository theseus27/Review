"""create question and choice models

Revision ID: 39fd220e0018
Revises: 
Create Date: 2021-11-20 10:17:29.831275

"""
from alembic import op
import sqlalchemy as sa


# revision identifiers, used by Alembic.
revision = '39fd220e0018'
down_revision = None
branch_labels = None
depends_on = None


def upgrade():
    # ### commands auto generated by Alembic - please adjust! ###
    op.create_table('poll_question',
    sa.Column('id', sa.Integer(), nullable=False),
    sa.Column('question_text', sa.String(length=200), nullable=False),
    sa.Column('pub_date', sa.DateTime(), nullable=False),
    sa.PrimaryKeyConstraint('id'),
    sa.UniqueConstraint('id')
    )
    op.create_table('poll_choice',
    sa.Column('id', sa.Integer(), nullable=False),
    sa.Column('choice_text', sa.String(length=200), nullable=False),
    sa.Column('votes', sa.Integer(), nullable=False),
    sa.Column('question_id', sa.Integer(), nullable=True),
    sa.ForeignKeyConstraint(['question_id'], ['poll_question.id'], ),
    sa.PrimaryKeyConstraint('id'),
    sa.UniqueConstraint('id')
    )
    # ### end Alembic commands ###


def downgrade():
    # ### commands auto generated by Alembic - please adjust! ###
    op.drop_table('poll_choice')
    op.drop_table('poll_question')
    # ### end Alembic commands ###
